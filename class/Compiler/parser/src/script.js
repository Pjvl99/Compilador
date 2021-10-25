'use strict';
(function($){
$(function() {
var datascource = 
{
 'name': 'program',  'title': '0',
'children' : [
{
 'name': 'class',  'title': '0', 'className': 'middle-level'},

{
 'name': 'program',  'title': '1', 'className': 'middle-level'},

{
 'name': '{',  'title': '2', 'className': 'middle-level'},

{
 'name': 'method_decl',  'title': '3', 'className': 'middle-level',
'children' : [
{
 'name': 'type',  'title': '3', 'className': 'product-dept'},

{
 'name': 'id',  'title': '4', 'className': 'product-dept'},

{
 'name': '(',  'title': '5', 'className': 'product-dept'},

{
 'name': ')',  'title': '6', 'className': 'product-dept'},

{
 'name': 'block',  'title': '7', 'className': 'product-dept',
'children' : [
{
 'name': '{',  'title': '7', 'className': 'pipeline1'},

{
 'name': 'statement',  'title': '8', 'className': 'pipeline1',
'children' : [
{
 'name': 'location',  'title': '8', 'className': 'rd-dept',
'children' : [
{
 'name': 'id',  'title': '8', 'className': 'frontend1'},

]
},
{
 'name': 'assign_op',  'title': '9', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': '10', 'className': 'rd-dept',
'children' : [
{
 'name': 'expr',  'title': '10', 'className': 'frontend1',
'children' : [
{
 'name': 'literal',  'title': '10', 'className': 'middle-level',
'children' : [
{
 'name': 'int_literal',  'title': '10', 'className': 'product-dept',
'children' : [
{
 'name': 'num',  'title': '10', 'className': 'pipeline1'},

]
}
]
}
]
},
{
 'name': 'bin_op',  'title': '11', 'className': 'frontend1',
'children' : [
{
 'name': 'arith_op',  'title': '11', 'className': 'middle-level'},

]
},
{
 'name': 'expr',  'title': '12', 'className': 'frontend1',
'children' : [
{
 'name': '(',  'title': '12', 'className': 'middle-level'},

{
 'name': 'expr',  'title': '13', 'className': 'middle-level',
'children' : [
{
 'name': 'expr',  'title': '13', 'className': 'product-dept',
'children' : [
{
 'name': 'literal',  'title': '13', 'className': 'pipeline1',
'children' : [
{
 'name': 'int_literal',  'title': '13', 'className': 'rd-dept',
'children' : [
{
 'name': 'num',  'title': '13', 'className': 'frontend1'},

]
}
]
}
]
},
{
 'name': 'bin_op',  'title': '14', 'className': 'product-dept',
'children' : [
{
 'name': 'arith_op',  'title': '14', 'className': 'pipeline1'},

]
},
{
 'name': 'expr',  'title': '15', 'className': 'product-dept',
'children' : [
{
 'name': 'literal',  'title': '15', 'className': 'pipeline1',
'children' : [
{
 'name': 'int_literal',  'title': '15', 'className': 'rd-dept',
'children' : [
{
 'name': 'num',  'title': '15', 'className': 'frontend1'},

]
}
]
}
]
}
]
},
{
 'name': ')',  'title': '16', 'className': 'middle-level'},

]
}
]
},
{
 'name': ';',  'title': '17', 'className': 'rd-dept'},

]
},
{
 'name': '}',  'title': '18', 'className': 'pipeline1'},

]
}
]
},
{
 'name': '}',  'title': '19', 'className': 'middle-level'},

]
};
var oc = $('#chart-container').orgchart({
'data' : datascource,
'nodeContent': 'title'
});
});
})(jQuery);
