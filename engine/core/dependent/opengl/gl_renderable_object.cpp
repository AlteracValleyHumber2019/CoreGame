#include "pav_pch.h"
#include "gl_renderable_object.h"

pav::GLRenderableObject::GLRenderableObject(ModelResource* model, IShaderResource* shader) :
	IRenderableObject(model, shader)
{
	// Set data
	model_mesh_ = model_res_->GetData();
	shader_program_ = dynamic_cast<OpenGLShaderProgram*>(shader_res_->GetData());

	// For each mesh
	for (size_t i = 0; i < model_mesh_.meshes.size(); i++)
	{
		GLRenderData render_data;

		Mesh current_mesh = model_mesh_.meshes.at(i);

		glGenVertexArrays(1, &render_data.vao);
		glBindVertexArray(render_data.vao);

		// Bind VBO
		glGenBuffers(1, &render_data.vbo);
		glBindBuffer(GL_ARRAY_BUFFER, render_data.vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * current_mesh.vertices.size(), &current_mesh.vertices[0], GL_STATIC_DRAW);

		// Bind EBO
		glGenBuffers(1, &render_data.ebo);
		render_data.indices_size = current_mesh.indices.size();
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, render_data.ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * current_mesh.indices.size(), &current_mesh.indices[0], GL_STATIC_DRAW);

		// Setup how to interpret vertex data
		// Position
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		glEnableVertexAttribArray(0);

		// Unbind
		glBindVertexArray(NULL);

		// Add to mesh
		render_meshes_.emplace_back(render_data);
	}
}

void pav::GLRenderableObject::Draw()
{
	// Use shader
	shader_program_->UseShader();

	// Draw mesh
	for (size_t i = 0; i < render_meshes_.size(); i++)
	{
		GLRenderData render_data = render_meshes_.at(i);

		glBindVertexArray(render_data.vao);
		glDrawElements(GL_TRIANGLES, render_data.indices_size, GL_UNSIGNED_INT, (void*)0);
		glBindVertexArray(NULL);
	}
}