// string
if ((typeof message) === 'string')  {
    console.log('string1111');
}

if ((typeof message) == 'string')  {
    console.log('string2222');
}

if (message.constructor == String) {
    console.log('string3333');
}


// object
if ((typeof message) === 'object')  {
    console.log('Object1111');
}

if ((typeof message) == 'object') {
    console.log("Object2222");     
}

// 无效XXXXXXXXX
if (message.constructor == Object) {
    console.log('Object3333');
}