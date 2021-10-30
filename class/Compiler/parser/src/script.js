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
 'name': 'field_decl',  'title': '3', 'className': 'middle-level',
'children' : [
{
 'name': 'type',  'title': '3', 'className': 'product-dept'},

{
 'name': 'id',  'title': '4', 'className': 'product-dept'},

{
 'name': ',',  'title': '5', 'className': 'product-dept'},

{
 'name': 'id',  'title': '6', 'className': 'product-dept'},

{
 'name': '[',  'title': '7', 'className': 'product-dept'},

{
 'name': 'int_literal',  'title': '8', 'className': 'product-dept',
'children' : [
{
 'name': 'num',  'title': '8', 'className': 'pipeline1'},

]
},
{
 'name': ']',  'title': '9', 'className': 'product-dept'},

{
 'name': ';',  'title': '10', 'className': 'product-dept'},

]
},
{
 'name': 'field_decl',  'title': '11', 'className': 'middle-level',
'children' : [
{
 'name': 'type',  'title': '11', 'className': 'product-dept'},

{
 'name': 'id',  'title': '12', 'className': 'product-dept'},

{
 'name': ',',  'title': '13', 'className': 'product-dept'},

{
 'name': 'id',  'title': '14', 'className': 'product-dept'},

{
 'name': ';',  'title': '15', 'className': 'product-dept'},

]
},
{
 'name': 'field_decl',  'title': '16', 'className': 'middle-level',
'children' : [
{
 'name': 'type',  'title': '16', 'className': 'product-dept'},

{
 'name': 'id',  'title': '17', 'className': 'product-dept'},

{
 'name': ',',  'title': '18', 'className': 'product-dept'},

{
 'name': 'id',  'title': '19', 'className': 'product-dept'},

{
 'name': ';',  'title': '20', 'className': 'product-dept'},

]
},
{
 'name': 'method_decl',  'title': '21', 'className': 'middle-level',
'children' : [
{
 'name': 'type',  'title': '21', 'className': 'product-dept'},

{
 'name': 'id',  'title': '22', 'className': 'product-dept'},

{
 'name': '(',  'title': '23', 'className': 'product-dept'},

{
 'name': 'type',  'title': '24', 'className': 'product-dept'},

{
 'name': 'id',  'title': '25', 'className': 'product-dept'},

{
 'name': ',',  'title': '26', 'className': 'product-dept'},

{
 'name': 'type',  'title': '27', 'className': 'product-dept'},

{
 'name': 'id',  'title': '28', 'className': 'product-dept'},

{
 'name': ')',  'title': '29', 'className': 'product-dept'},

{
 'name': 'block',  'title': '30', 'className': 'product-dept',
'children' : [
{
 'name': '{',  'title': '30', 'className': 'pipeline1'},

{
 'name': 'var_decl',  'title': '31', 'className': 'pipeline1',
'children' : [
{
 'name': 'type',  'title': '31', 'className': 'rd-dept'},

{
 'name': 'id',  'title': '32', 'className': 'rd-dept'},

{
 'name': ';',  'title': '33', 'className': 'rd-dept'},

]
},
{
 'name': 'statement',  'title': '34', 'className': 'pipeline1',
'children' : [
{
 'name': 'location',  'title': '34', 'className': 'rd-dept',
'children' : [
{
 'name': 'id',  'title': '34', 'className': 'frontend1'},

]
},
{
 'name': 'assign_op',  'title': '35', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': '36', 'className': 'rd-dept',
'children' : [
{
 'name': 'method_call',  'title': '36', 'className': 'frontend1',
'children' : [
{
 'name': 'id',  'title': '36', 'className': 'middle-level'},

{
 'name': '(',  'title': '37', 'className': 'middle-level'},

{
 'name': 'expr',  'title': '38', 'className': 'middle-level',
'children' : [
{
 'name': 'location',  'title': '38', 'className': 'product-dept',
'children' : [
{
 'name': 'id',  'title': '38', 'className': 'pipeline1'},

]
}
]
},
{
 'name': ',',  'title': '39', 'className': 'middle-level'},

{
 'name': 'expr',  'title': '40', 'className': 'middle-level',
'children' : [
{
 'name': 'expr',  'title': '40', 'className': 'product-dept',
'children' : [
{
 'name': 'literal',  'title': '40', 'className': 'pipeline1',
'children' : [
{
 'name': 'int_literal',  'title': '40', 'className': 'rd-dept',
'children' : [
{
 'name': 'num',  'title': '40', 'className': 'frontend1'},

]
}
]
}
]
},
{
 'name': 'bin_op',  'title': '41', 'className': 'product-dept',
'children' : [
{
 'name': 'arith_op',  'title': '41', 'className': 'pipeline1'},

]
},
{
 'name': 'expr',  'title': '42', 'className': 'product-dept',
'children' : [
{
 'name': 'literal',  'title': '42', 'className': 'pipeline1',
'children' : [
{
 'name': 'int_literal',  'title': '42', 'className': 'rd-dept',
'children' : [
{
 'name': 'num',  'title': '42', 'className': 'frontend1'},

]
}
]
}
]
}
]
},
{
 'name': ')',  'title': '43', 'className': 'middle-level'},

]
}
]
},
{
 'name': ';',  'title': '44', 'className': 'rd-dept'},

]
},
{
 'name': 'statement',  'title': '45', 'className': 'pipeline1',
'children' : [
{
 'name': 'location',  'title': '45', 'className': 'rd-dept',
'children' : [
{
 'name': 'id',  'title': '45', 'className': 'frontend1'},

]
},
{
 'name': 'assign_op',  'title': '46', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': '47', 'className': 'rd-dept',
'children' : [
{
 'name': 'location',  'title': '47', 'className': 'frontend1',
'children' : [
{
 'name': 'location2',  'title': '47', 'className': 'middle-level',
'children' : [
{
 'name': 'id',  'title': '47', 'className': 'product-dept'},

{
 'name': '[',  'title': '48', 'className': 'product-dept'},

{
 'name': 'expr',  'title': '49', 'className': 'product-dept',
'children' : [
{
 'name': 'literal',  'title': '49', 'className': 'pipeline1',
'children' : [
{
 'name': 'int_literal',  'title': '49', 'className': 'rd-dept',
'children' : [
{
 'name': 'num',  'title': '49', 'className': 'frontend1'},

]
}
]
}
]
},
{
 'name': ']',  'title': '50', 'className': 'product-dept'},

]
}
]
}
]
},
{
 'name': ';',  'title': '51', 'className': 'rd-dept'},

]
},
{
 'name': 'statement',  'title': '52', 'className': 'pipeline1',
'children' : [
{
 'name': 'return',  'title': '52', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': '53', 'className': 'rd-dept',
'children' : [
{
 'name': 'location',  'title': '53', 'className': 'frontend1',
'children' : [
{
 'name': 'id',  'title': '53', 'className': 'middle-level'},

]
}
]
},
{
 'name': ';',  'title': '54', 'className': 'rd-dept'},

]
},
{
 'name': '}',  'title': '55', 'className': 'pipeline1'},

]
}
]
},
{
 'name': 'method_decl',  'title': '56', 'className': 'middle-level',
'children' : [
{
 'name': 'void',  'title': '56', 'className': 'product-dept'},

{
 'name': 'id',  'title': '57', 'className': 'product-dept'},

{
 'name': '(',  'title': '58', 'className': 'product-dept'},

{
 'name': ')',  'title': '59', 'className': 'product-dept'},

{
 'name': 'block',  'title': '60', 'className': 'product-dept',
'children' : [
{
 'name': '{',  'title': '60', 'className': 'pipeline1'},

{
 'name': 'var_decl',  'title': '61', 'className': 'pipeline1',
'children' : [
{
 'name': 'type',  'title': '61', 'className': 'rd-dept'},

{
 'name': 'id',  'title': '62', 'className': 'rd-dept'},

{
 'name': ';',  'title': '63', 'className': 'rd-dept'},

]
},
{
 'name': 'statement',  'title': '64', 'className': 'pipeline1',
'children' : [
{
 'name': 'location',  'title': '64', 'className': 'rd-dept',
'children' : [
{
 'name': 'id',  'title': '64', 'className': 'frontend1'},

]
},
{
 'name': 'assign_op',  'title': '65', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': '66', 'className': 'rd-dept',
'children' : [
{
 'name': 'method_call',  'title': '66', 'className': 'frontend1',
'children' : [
{
 'name': 'id',  'title': '66', 'className': 'middle-level'},

{
 'name': '(',  'title': '67', 'className': 'middle-level'},

{
 'name': 'expr',  'title': '68', 'className': 'middle-level',
'children' : [
{
 'name': 'literal',  'title': '68', 'className': 'product-dept',
'children' : [
{
 'name': 'int_literal',  'title': '68', 'className': 'pipeline1',
'children' : [
{
 'name': 'num',  'title': '68', 'className': 'rd-dept'},

]
}
]
}
]
},
{
 'name': ',',  'title': '69', 'className': 'middle-level'},

{
 'name': 'expr',  'title': '70', 'className': 'middle-level',
'children' : [
{
 'name': 'literal',  'title': '70', 'className': 'product-dept',
'children' : [
{
 'name': 'int_literal',  'title': '70', 'className': 'pipeline1',
'children' : [
{
 'name': 'num',  'title': '70', 'className': 'rd-dept'},

]
}
]
}
]
},
{
 'name': ')',  'title': '71', 'className': 'middle-level'},

]
}
]
},
{
 'name': ';',  'title': '72', 'className': 'rd-dept'},

]
},
{
 'name': '}',  'title': '73', 'className': 'pipeline1'},

]
}
]
},
{
 'name': '}',  'title': '74', 'className': 'middle-level'},

]
};
var oc = $('#chart-container').orgchart({
'data' : datascource,
'nodeContent': 'title'
});
});
})(jQuery);
