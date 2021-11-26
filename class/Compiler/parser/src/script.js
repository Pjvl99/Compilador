'use strict';
(function($){
$(function() {
var datascource = 
{
 'name': 'program',  'title': '',
'children' : [
{
 'name': 'class',  'title': '', 'className': 'middle-level'},

{
 'name': 'program',  'title': '', 'className': 'middle-level'},

{
 'name': '{',  'title': '', 'className': 'middle-level'},

{
 'name': 'field_decl',  'title': '', 'className': 'middle-level',
'children' : [
{
 'name': 'type',  'title': '', 'className': 'product-dept'},

{
 'name': 'id',  'title': 'int', 'className': 'product-dept'},

{
 'name': ';',  'title': '', 'className': 'product-dept'},

]
},
{
 'name': 'method_decl',  'title': '', 'className': 'middle-level',
'children' : [
{
 'name': 'type',  'title': '', 'className': 'product-dept'},

{
 'name': 'id',  'title': 'int', 'className': 'product-dept'},

{
 'name': '(',  'title': '', 'className': 'product-dept'},

{
 'name': ')',  'title': '', 'className': 'product-dept'},

{
 'name': 'block',  'title': '', 'className': 'product-dept',
'children' : [
{
 'name': '{',  'title': '', 'className': 'pipeline1'},

{
 'name': 'var_decl',  'title': '', 'className': 'pipeline1',
'children' : [
{
 'name': 'type',  'title': '', 'className': 'rd-dept'},

{
 'name': 'id',  'title': 'int', 'className': 'rd-dept'},

{
 'name': ',',  'title': '', 'className': 'rd-dept'},

{
 'name': 'id',  'title': 'int', 'className': 'rd-dept'},

{
 'name': ';',  'title': '', 'className': 'rd-dept'},

]
},
{
 'name': 'statement',  'title': '', 'className': 'pipeline1',
'children' : [
{
 'name': 'location',  'title': 'int', 'className': 'rd-dept',
'children' : [
{
 'name': 'id',  'title': 'int', 'className': 'frontend1'},

]
},
{
 'name': 'assign_op',  'title': '', 'className': 'rd-dept',
'children' : [
{
 'name': '=',  'title': '', 'className': 'frontend1'},

]
},
{
 'name': 'expr',  'title': 'int', 'className': 'rd-dept',
'children' : [
{
 'name': 'expr',  'title': 'int', 'className': 'frontend1',
'children' : [
{
 'name': 'literal',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'int_literal',  'title': 'int', 'className': 'product-dept',
'children' : [
{
 'name': 'num',  'title': 'int', 'className': 'pipeline1'},

]
}
]
}
]
},
{
 'name': 'bin_op',  'title': '', 'className': 'frontend1',
'children' : [
{
 'name': 'arith_op',  'title': '', 'className': 'middle-level',
'children' : [
{
 'name': '+',  'title': '', 'className': 'product-dept'},

]
}
]
},
{
 'name': 'expr',  'title': 'int', 'className': 'frontend1',
'children' : [
{
 'name': 'literal',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'int_literal',  'title': 'int', 'className': 'product-dept',
'children' : [
{
 'name': 'num',  'title': 'int', 'className': 'pipeline1'},

]
}
]
}
]
}
]
},
{
 'name': ';',  'title': '', 'className': 'rd-dept'},

]
},
{
 'name': 'statement',  'title': '', 'className': 'pipeline1',
'children' : [
{
 'name': 'if',  'title': '', 'className': 'rd-dept'},

{
 'name': '(',  'title': '', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': 'int', 'className': 'rd-dept',
'children' : [
{
 'name': 'expr',  'title': 'int', 'className': 'frontend1',
'children' : [
{
 'name': 'location',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'id',  'title': 'int', 'className': 'product-dept'},

]
}
]
},
{
 'name': 'bin_op',  'title': '', 'className': 'frontend1',
'children' : [
{
 'name': 'rel_op',  'title': '', 'className': 'middle-level',
'children' : [
{
 'name': '<',  'title': '', 'className': 'product-dept'},

]
}
]
},
{
 'name': 'expr',  'title': 'int', 'className': 'frontend1',
'children' : [
{
 'name': 'literal',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'int_literal',  'title': 'int', 'className': 'product-dept',
'children' : [
{
 'name': 'num',  'title': 'int', 'className': 'pipeline1'},

]
}
]
}
]
}
]
},
{
 'name': ')',  'title': '', 'className': 'rd-dept'},

{
 'name': 'block',  'title': '', 'className': 'rd-dept',
'children' : [
{
 'name': '{',  'title': '', 'className': 'frontend1'},

{
 'name': 'statement',  'title': '', 'className': 'frontend1',
'children' : [
{
 'name': 'location',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'id',  'title': 'int', 'className': 'product-dept'},

]
},
{
 'name': 'assign_op',  'title': '', 'className': 'middle-level',
'children' : [
{
 'name': '=',  'title': '', 'className': 'product-dept'},

]
},
{
 'name': 'expr',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'expr',  'title': 'int', 'className': 'product-dept',
'children' : [
{
 'name': 'literal',  'title': 'int', 'className': 'pipeline1',
'children' : [
{
 'name': 'int_literal',  'title': 'int', 'className': 'rd-dept',
'children' : [
{
 'name': 'num',  'title': 'int', 'className': 'frontend1'},

]
}
]
}
]
},
{
 'name': 'bin_op',  'title': '', 'className': 'product-dept',
'children' : [
{
 'name': 'arith_op',  'title': '', 'className': 'pipeline1',
'children' : [
{
 'name': '*',  'title': '', 'className': 'rd-dept'},

]
}
]
},
{
 'name': 'expr',  'title': 'int', 'className': 'product-dept',
'children' : [
{
 'name': 'literal',  'title': 'int', 'className': 'pipeline1',
'children' : [
{
 'name': 'int_literal',  'title': 'int', 'className': 'rd-dept',
'children' : [
{
 'name': 'num',  'title': 'int', 'className': 'frontend1'},

]
}
]
}
]
}
]
},
{
 'name': ';',  'title': '', 'className': 'middle-level'},

]
},
{
 'name': '}',  'title': '', 'className': 'frontend1'},

]
},
{
 'name': 'else',  'title': '', 'className': 'rd-dept'},

{
 'name': 'block',  'title': '', 'className': 'rd-dept',
'children' : [
{
 'name': '{',  'title': '', 'className': 'frontend1'},

{
 'name': 'statement',  'title': '', 'className': 'frontend1',
'children' : [
{
 'name': 'location',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'id',  'title': 'int', 'className': 'product-dept'},

]
},
{
 'name': 'assign_op',  'title': '', 'className': 'middle-level',
'children' : [
{
 'name': '=',  'title': '', 'className': 'product-dept'},

]
},
{
 'name': 'expr',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'expr',  'title': 'int', 'className': 'product-dept',
'children' : [
{
 'name': 'literal',  'title': 'int', 'className': 'pipeline1',
'children' : [
{
 'name': 'int_literal',  'title': 'int', 'className': 'rd-dept',
'children' : [
{
 'name': 'num',  'title': 'int', 'className': 'frontend1'},

]
}
]
}
]
},
{
 'name': 'bin_op',  'title': '', 'className': 'product-dept',
'children' : [
{
 'name': 'arith_op',  'title': '', 'className': 'pipeline1',
'children' : [
{
 'name': '*',  'title': '', 'className': 'rd-dept'},

]
}
]
},
{
 'name': 'expr',  'title': 'int', 'className': 'product-dept',
'children' : [
{
 'name': 'literal',  'title': 'int', 'className': 'pipeline1',
'children' : [
{
 'name': 'int_literal',  'title': 'int', 'className': 'rd-dept',
'children' : [
{
 'name': 'num',  'title': 'int', 'className': 'frontend1'},

]
}
]
}
]
}
]
},
{
 'name': ';',  'title': '', 'className': 'middle-level'},

]
},
{
 'name': '}',  'title': '', 'className': 'frontend1'},

]
}
]
},
{
 'name': 'statement',  'title': '', 'className': 'pipeline1',
'children' : [
{
 'name': 'for',  'title': '', 'className': 'rd-dept'},

{
 'name': 'id',  'title': 'int', 'className': 'rd-dept'},

{
 'name': '=',  'title': '', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': 'int', 'className': 'rd-dept',
'children' : [
{
 'name': 'literal',  'title': 'int', 'className': 'frontend1',
'children' : [
{
 'name': 'int_literal',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'num',  'title': 'int', 'className': 'product-dept'},

]
}
]
}
]
},
{
 'name': ',',  'title': '', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': 'int', 'className': 'rd-dept',
'children' : [
{
 'name': 'expr',  'title': 'int', 'className': 'frontend1',
'children' : [
{
 'name': 'location',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'id',  'title': 'int', 'className': 'product-dept'},

]
}
]
},
{
 'name': 'bin_op',  'title': '', 'className': 'frontend1',
'children' : [
{
 'name': 'rel_op',  'title': '', 'className': 'middle-level',
'children' : [
{
 'name': '<',  'title': '', 'className': 'product-dept'},

]
}
]
},
{
 'name': 'expr',  'title': 'int', 'className': 'frontend1',
'children' : [
{
 'name': 'literal',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'int_literal',  'title': 'int', 'className': 'product-dept',
'children' : [
{
 'name': 'num',  'title': 'int', 'className': 'pipeline1'},

]
}
]
}
]
}
]
},
{
 'name': 'block',  'title': '', 'className': 'rd-dept',
'children' : [
{
 'name': '{',  'title': '', 'className': 'frontend1'},

{
 'name': 'statement',  'title': '', 'className': 'frontend1',
'children' : [
{
 'name': 'location',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'id',  'title': 'int', 'className': 'product-dept'},

]
},
{
 'name': 'assign_op',  'title': '', 'className': 'middle-level',
'children' : [
{
 'name': '+=',  'title': '', 'className': 'product-dept'},

]
},
{
 'name': 'expr',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'literal',  'title': 'int', 'className': 'product-dept',
'children' : [
{
 'name': 'int_literal',  'title': 'int', 'className': 'pipeline1',
'children' : [
{
 'name': 'num',  'title': 'int', 'className': 'rd-dept'},

]
}
]
}
]
},
{
 'name': ';',  'title': '', 'className': 'middle-level'},

]
},
{
 'name': '}',  'title': '', 'className': 'frontend1'},

]
}
]
},
{
 'name': 'statement',  'title': '', 'className': 'pipeline1',
'children' : [
{
 'name': 'return',  'title': '', 'className': 'rd-dept'},

{
 'name': 'expr',  'title': 'int', 'className': 'rd-dept',
'children' : [
{
 'name': 'literal',  'title': 'int', 'className': 'frontend1',
'children' : [
{
 'name': 'int_literal',  'title': 'int', 'className': 'middle-level',
'children' : [
{
 'name': 'num',  'title': 'int', 'className': 'product-dept'},

]
}
]
}
]
},
{
 'name': ';',  'title': '', 'className': 'rd-dept'},

]
},
{
 'name': '}',  'title': '', 'className': 'pipeline1'},

]
}
]
},
{
 'name': '}',  'title': '', 'className': 'middle-level'},

]
};
var oc = $('#chart-container').orgchart({
'data' : datascource,
'nodeContent': 'title'
});
});
})(jQuery);
