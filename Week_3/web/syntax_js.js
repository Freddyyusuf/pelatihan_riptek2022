//komentar tdk akan dieksekusi

//print
console.log("hello");


//deklarasi variable
const b = 5 // tidak bisa dirubah
let a = 10  // bisa diubah
var c = 1   // bisa diubah, tdk peduli scope


// if
let a = 1
if (a == 1) {
    // dieksekusi
} else {
    // tdk dieksekusi
}


//while
let i = 0
while (i < 5) {
    console.log(i);
    i++
}


//for
for (let i = 0; i < 5; i++) {
    console.log(i);
}


//array
let a = [1, 2, 3]
console.log(a.length); //3
console.log(a[1]);
a.push(4)
a.pop()


//string
let a = "ab"
let b = "cd"
let num = 5
console.log(a + b);   //"abcd"
console.log(a + num); //"ab5"
console.log("nilai num: " + num);
console.log(`nilai num: ${num}`);


//fungsi
function namaFungsi1(parameter) {
    //code
}
const namaFungsi2 = function (parameter) {
    //code
}
const namaFungsi3 = (parameter) => {
    //code
}


//object
const obj = {
    key: "value"
}
console.log(obj.key); //"value"


