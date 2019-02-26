var EmojiCharts = new function() {
	this.init = function(selector, data) {
		var parent_tbl = document.createElement('table');
			parent_tbl.setAttribute("class","parent_tbl");
			var parent_tr = parent_tbl.insertRow();

		$.each(data, function(key1, value1){
			if ((key1 > 0)&&(typeof value1[0] !== 'undefined' ))  {

				var parent_td = parent_tr.insertCell();
				var tbl = document.createElement('table');
				tbl.setAttribute("class","union_tbl");
				var tr = tbl.insertRow();
				tr.style.height='69px';
				tr.style.borderTop='1px solid #ccc';
				tr.style.verticalAlign='bottom';
				var td = tr.insertCell();
				$(td).html("<h2>&nbsp</h2>");
				$.each(value1, function(key, value){
					var tr = tbl.insertRow();
					tr.style.height='50px';
					tr.style.verticalAlign='bottom';
					var td = tr.insertCell();
					if (value.union_low < 0) {
						var html = "0";
					} else {
						var html = '<span class="badge '
						if (value.person_x_y_avg_similarity > 75) {
							html += 'feedback_badge_high';
						} else if (value.person_x_y_avg_similarity > 40) {
							html += 'feedback_badge_med';
						} else if (value.person_x_y_avg_similarity > 0) {
							html += 'feedback_badge_low';
						}
						html += ' popovers" data-container="body" data-trigger="hover" data-placement="top" data-content="' + value.person_x_y_avg_similarity_text + '">&nbsp;&nbsp;' + value.person_x_y_avg_similarity + '%&nbsp;&nbsp;</span>';
					}
					$(td).html(html);

					$(selector).append(parent_tbl);
				});

				var parent_td = parent_tr.insertCell();
				$(parent_td).html(tbl);
			}
			var parent_td = parent_tr.insertCell();
			var tbl = document.createElement('table');
			tbl.setAttribute("class","chart_tbl");
			var tr = tbl.insertRow();
			tr.style.height='50px';
			tr.style.verticalAlign='bottom';
			var td = tr.insertCell();
			td.setAttribute('colspan', '4');
			if ( typeof value1[0] !== 'undefined' ) {
				$(td).html("<h2>" + value1[0]['person_name'] + "</h2>");
			}
			$.each(value1, function(key, value){
				var tr = tbl.insertRow();
				tr.style.height='50px';
				tr.style.verticalAlign='bottom';
				tr.setAttribute("class","popovers");
				tr.setAttribute("data-container","body");
				tr.setAttribute("data-trigger","hover");
				tr.setAttribute("data-placement","top");
				tr.setAttribute("data-html","true");
				tr.setAttribute("data-original-title", '<b>' + value.construct_name + '</b>');
				var popText = "";
				if (value.construct_description != "") {
					popText += value.construct_description;
				}
				if (value.construct_description_specific != "") {
					popText += '<br><br><b>Analysis: </b>' +value.construct_description_specific;
				}
				if (value.value_confidence != "") {
					popText += '<br><br><span class="badge badge-default">' + value.value_confidence + '% precise</span>';
				} else {
					popText += '<br><br><span class="badge badge-default">0% precise</span>';
				}
				tr.setAttribute("data-content",popText);

				if (value.value_avg > 99) {
					value.value_avg = 99;
				}
				var width_avg = getWidth(value.value_avg, value.scale_low, value.scale_high);


				if (width_avg < 50) {
					var width_low = 0;
					var width_high = width_avg -1;
					var width_avg = width_avg +1;
				} else if (width_avg > 50) {
					var width_low = width_avg -1;
					var width_avg = width_avg + 1;
					var width_high = 100;
				} else {
					var width_low = width_high = width_avg;
				}

				if ( typeof value.value_low !== 'undefined' ) {
					var width_low = getWidth(value.value_low, value.scale_low, value.scale_high);
				} else {
					var avg_hack = true;
				}
				if ( typeof value.value_high !== 'undefined' ) {
					var width_high = getWidth(value.value_high, value.scale_low, value.scale_high);
				}

				if (width_low > width_avg) {
					width_low = width_avg;
				}
				if (width_high < width_avg) {
					width_high = width_avg;
				}



				var html ='<div class="chart-block">'+
										'<div style="vertical-align: middle; display: inline-block; width: 200px; height: 20px;">'+
											'<div class="basic_chart_bg">'+
												'<div class="basic_chart_spacer" style="width:';
				html += 					width_low;
				html += 						'%"><span class="basic_chart_min"><span class="basic_chart_text">';
				html += 					value.value_low;
				html += 				'<span></span></div>'+
												'<div class="basic_chart_fg" style="width:';
				html += 				(width_avg - width_low);
				html += 				'%"><span class="basic_chart_avg"';
				if (avg_hack) {
					html+= 'style="right: 16px;"';
				}
				html += 				'><span><span>';
				html +=					value.value_avg;
				html +=					'%</span></span></span></div>'+
												'<div class="basic_chart_fg" style="width:';
				html += 				(width_high - width_avg);
				html += 				'%"></div>'+
												'<div class="basic_chart_spacer" style="width:';
				html += 				(100 - width_high);
				html += 				'"%"><span class="basic_chart_max"><span class="basic_chart_text">';
				html += 				value.value_high;
				html +=					'<span></span></div>'+
											'</div>'+
										'</div>'+
									'</div>';

				var td = tr.insertCell();
				td.appendChild(document.createTextNode(value.anchor_low));
				td.setAttribute('class', 'row-2 row-low');
				if (value.trinary == -1) {
					td.classList.add('highlight');
				}

				var td = tr.insertCell();
				td.setAttribute('class', 'row-3 row-chart');
				$(td).html(html);

				var td = tr.insertCell();
				td.appendChild(document.createTextNode(value.anchor_high));
				td.setAttribute('class', 'row-4 row-high');

				if (value.trinary == 1) {
					td.classList.add('highlight');
				}




			});
			var parent_td = parent_tr.insertCell();
			$(parent_td).html(tbl);
			//$(selector).append(tbl);
		});

		$(selector).append(parent_tbl);

	};
	function getWidth (val, low, high) {
	var v = ((val-low)/(high-low)) * 100;
	return v;
	};
}
