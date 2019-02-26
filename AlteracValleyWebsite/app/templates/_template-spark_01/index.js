$("btn").click(function(){
  app.post('/',function(req,res){
    console.log(req.body);
  });
});
