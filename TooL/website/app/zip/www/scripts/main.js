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
/*SELECT * 
FROM Final_compile_memory
WHERE id =1
UNION ALL SELECT * 
FROM Final_compile_time
WHERE id =1
UNION ALL SELECT * 
FROM Final_LOC
WHERE id =1
UNION ALL SELECT * 
FROM Final_run_memory
WHERE id =1
UNION ALL SELECT * 
FROM Final_run_time
WHERE id =1 */
		{ val:"basic" , text:"Basic"},
		{ val:"graph" , text:"Graph Algorithms"},
		{ val:"misc" , text:"Miscellaneous"},
		{ val:"np" , text:"NP - Hard"},
		{ val:"numerical" , text:"Numerical Computation"},
		{ val:"web", text:"Web Programming"}
	];
	options['language']=[
/*
SELECT k.c, l.c, m.c, n.c, o.c
FROM Final_compile_memory AS k, Final_compile_time AS l, Final_LOC AS m, Final_run_memory AS n, Final_run_time AS o
WHERE k.id = l.id
AND l.id = m.id
AND m.id = n.id
AND n.id = o.id
*/
		{ val:"c" , text:"C"},
		{ val:"cpp" , text:"C++"},
		{ val:"haskell" , text:"Haskell"},
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
