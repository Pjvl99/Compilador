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
 'name': 'statement',  'title': '31', 'className': 'pipeline1',
'children' : [
{
 'name': 'location',  'title': '31', 'className': 'rd-dept',
'children' : [
{
 'name': 'id',  'title': '31', 'className': 'frontend1'},

]
},
{
 'name': 'assign_op',  'title': '32', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': '33', 'className': 'rd-dept',
'children' : [
{
 'name': 'expr',  'title': '33', 'className': 'frontend1',
'children' : [
{
 'name': 'literal',  'title': '33', 'className': 'middle-level',
'children' : [
{
 'name': 'int_literal',  'title': '33', 'className': 'product-dept',
'children' : [
{
 'name': 'num',  'title': '33', 'className': 'pipeline1'},

]
}
]
}
]
},
{
 'name': 'bin_op',  'title': '34', 'className': 'frontend1',
'children' : [
{
 'name': 'arith_op',  'title': '34', 'className': 'middle-level'},

]
},
{
 'name': 'expr',  'title': '35', 'className': 'frontend1',
'children' : [
{
 'name': 'literal',  'title': '35', 'className': 'middle-level',
'children' : [
{
 'name': 'int_literal',  'title': '35', 'className': 'product-dept',
'children' : [
{
 'name': 'num',  'title': '35', 'className': 'pipeline1'},

]
}
]
}
]
}
]
},
{
 'name': ';',  'title': '36', 'className': 'rd-dept'},

]
},
{
 'name': 'statement',  'title': '37', 'className': 'pipeline1',
'children' : [
{
 'name': 'location',  'title': '37', 'className': 'rd-dept',
'children' : [
{
 'name': 'id',  'title': '37', 'className': 'frontend1'},

]
},
{
 'name': 'assign_op',  'title': '38', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': '39', 'className': 'rd-dept',
'children' : [
{
 'name': 'method_call',  'title': '39', 'className': 'frontend1',
'children' : [
{
 'name': 'id',  'title': '39', 'className': 'middle-level'},

{
 'name': '(',  'title': '40', 'className': 'middle-level'},

{
 'name': 'expr',  'title': '41', 'className': 'middle-level',
'children' : [
{
 'name': 'location',  'title': '41', 'className': 'product-dept',
'children' : [
{
 'name': 'id',  'title': '41', 'className': 'pipeline1'},

]
}
]
},
{
 'name': ',',  'title': '42', 'className': 'middle-level'},

{
 'name': 'expr',  'title': '43', 'className': 'middle-level',
'children' : [
{
 'name': 'literal',  'title': '43', 'className': 'product-dept',
'children' : [
{
 'name': 'int_literal',  'title': '43', 'className': 'pipeline1',
'children' : [
{
 'name': 'num',  'title': '43', 'className': 'rd-dept'},

]
}
]
}
]
},
{
 'name': ')',  'title': '44', 'className': 'middle-level'},

]
}
]
},
{
 'name': ';',  'title': '45', 'className': 'rd-dept'},

]
},
{
 'name': 'statement',  'title': '46', 'className': 'pipeline1',
'children' : [
{
 'name': 'location',  'title': '46', 'className': 'rd-dept',
'children' : [
{
 'name': 'id',  'title': '46', 'className': 'frontend1'},

]
},
{
 'name': 'assign_op',  'title': '47', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': '48', 'className': 'rd-dept',
'children' : [
{
 'name': 'location',  'title': '48', 'className': 'frontend1',
'children' : [
{
 'name': 'location2',  'title': '48', 'className': 'middle-level',
'children' : [
{
 'name': 'id',  'title': '48', 'className': 'product-dept'},

{
 'name': '[',  'title': '49', 'className': 'product-dept'},

{
 'name': 'expr',  'title': '50', 'className': 'product-dept',
'children' : [
{
 'name': 'literal',  'title': '50', 'className': 'pipeline1',
'children' : [
{
 'name': 'int_literal',  'title': '50', 'className': 'rd-dept',
'children' : [
{
 'name': 'num',  'title': '50', 'className': 'frontend1'},

]
}
]
}
]
},
{
 'name': ']',  'title': '51', 'className': 'product-dept'},

]
}
]
}
]
},
{
 'name': ';',  'title': '52', 'className': 'rd-dept'},

]
},
{
 'name': 'statement',  'title': '53', 'className': 'pipeline1',
'children' : [
{
 'name': 'return',  'title': '53', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': '54', 'className': 'rd-dept',
'children' : [
{
 'name': 'literal',  'title': '54', 'className': 'frontend1',
'children' : [
{
 'name': 'int_literal',  'title': '54', 'className': 'middle-level',
'children' : [
{
 'name': 'num',  'title': '54', 'className': 'product-dept'},

]
}
]
}
]
},
{
 'name': ';',  'title': '55', 'className': 'rd-dept'},

]
},
{
 'name': '}',  'title': '56', 'className': 'pipeline1'},

]
}
]
},
{
 'name': 'method_decl',  'title': '57', 'className': 'middle-level',
'children' : [
{
 'name': 'void',  'title': '57', 'className': 'product-dept'},

{
 'name': 'id',  'title': '58', 'className': 'product-dept'},

{
 'name': '(',  'title': '59', 'className': 'product-dept'},

{
 'name': ')',  'title': '60', 'className': 'product-dept'},

{
 'name': 'block',  'title': '61', 'className': 'product-dept',
'children' : [
{
 'name': '{',  'title': '61', 'className': 'pipeline1'},

{
 'name': 'var_decl',  'title': '62', 'className': 'pipeline1',
'children' : [
{
 'name': 'type',  'title': '62', 'className': 'rd-dept'},

{
 'name': 'id',  'title': '63', 'className': 'rd-dept'},

{
 'name': ';',  'title': '64', 'className': 'rd-dept'},

]
},
{
 'name': 'statement',  'title': '65', 'className': 'pipeline1',
'children' : [
{
 'name': 'location',  'title': '65', 'className': 'rd-dept',
'children' : [
{
 'name': 'id',  'title': '65', 'className': 'frontend1'},

]
},
{
 'name': 'assign_op',  'title': '66', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': '67', 'className': 'rd-dept',
'children' : [
{
 'name': 'literal',  'title': '67', 'className': 'frontend1',
'children' : [
{
 'name': 'int_literal',  'title': '67', 'className': 'middle-level',
'children' : [
{
 'name': 'num',  'title': '67', 'className': 'product-dept'},

]
}
]
}
]
},
{
 'name': ';',  'title': '68', 'className': 'rd-dept'},

]
},
{
 'name': 'statement',  'title': '69', 'className': 'pipeline1',
'children' : [
{
 'name': 'return',  'title': '69', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': '70', 'className': 'rd-dept',
'children' : [
{
 'name': 'location',  'title': '70', 'className': 'frontend1',
'children' : [
{
 'name': 'id',  'title': '70', 'className': 'middle-level'},

]
}
]
},
{
 'name': ';',  'title': '71', 'className': 'rd-dept'},

]
},
{
 'name': '}',  'title': '72', 'className': 'pipeline1'},

]
}
]
},
{
 'name': '}',  'title': '73', 'className': 'middle-level'},

]
};
var oc = $('#chart-container').orgchart({
'data' : datascource,
'nodeContent': 'title'
});
});
})(jQuery);
