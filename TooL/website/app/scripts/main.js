require.config({
    paths: {
        jquery: '../components/jquery/jquery',
        bootstrap: 'vendor/bootstrap'
    },
    shim: {
        bootstrap: {
            deps: ['jquery'],
            exports: 'jquery'
        }
    }
});

require(['app', 'jquery', 'bootstrap'], function (app, $) {
    'use strict';
    // use app here
    console.log(app);
	var options=Array();
	options['attribute']=[
		{ val:"compile_memory" , text:"Compile Memory"},
		{ val:"compile_time" , text:"Compile Time"},
		{ val:"LOC" , text:"Lines of Code"},
		{ val:"run_memory" , text:"Runtime Memory"},
		{ val:"run_time" , text:"Run Time"}
	];
	options['domain']=[
		{ val:"basic" , text:"Basic"},
		{ val:"graph" , text:"Graph Algorithms"},
		{ val:"misc" , text:"Miscellaneous"},
		{ val:"np" , text:"NP - Hard"},
		{ val:"numerical" , text:"Numerical Computation"},
		{ val:"web", text:"Web Programming"}
	];
	options['language']=[
		{ val:"c" , text:"C"},
		{ val:"cpp" , text:"C++"},
		{ val:"hs" , text:"Haskell"},
		{ val:"java" , text:"JAVA"},
		{ val:"python" , text:"Python"},
		{ val:"cython" , text:"Cython"}
	];
    console.log('Running jQuery %s', $().jquery);
    $('#primary').change(function() {
	var primary= $("select#primary option:selected").val();
	$('#secondary').html("");
	$.each(options[primary], function(index,opt){
		$('#secondary').append('<option value="'+opt.val+'">'+opt.text+'</option>');
	});
	// Force change trigger for secondary
	$('#secondary').change();
    });
    $('#secondary').change(function() {
	var primary= $("select#primary option:selected").val();
	var secondary= $("select#secondary option:selected").val();
 	$.ajax('fetch.php?type='+primary+'&param='+secondary).done(function(data){
 	$('#result').html(data);
 	});
	});
	// Force change trigger for primary
    $('#primary').change();
});
