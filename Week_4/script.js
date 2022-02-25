// Import the functions you need from the SDKs you need
import { initializeApp } from "https://www.gstatic.com/firebasejs/9.6.6/firebase-app.js";
import {
  getDatabase,
  ref,
  set,
  onValue,
} from "https://www.gstatic.com/firebasejs/9.6.6/firebase-database.js";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyBLpjUY7GqoSToPllwPVK2Z-Y6kU5IyOJQ",
  authDomain: "coba-firebase-6e579.firebaseapp.com",
  databaseURL:
    "https://coba-firebase-6e579-default-rtdb.asia-southeast1.firebasedatabase.app",
  projectId: "coba-firebase-6e579",
  storageBucket: "coba-firebase-6e579.appspot.com",
  messagingSenderId: "543429515189",
  appId: "1:543429515189:web:ba3c0ca8954d9f6a53abfc",
};

// Initialize Firebase

const app = initializeApp(firebaseConfig);
const db = getDatabase(app);

function writeDB(key, value) {
  set(ref(db, key), value);
}


//binding component
const cm = document.getElementById("cm");
const inch = document.getElementById("inch");

//watch data firebase
onValue(ref(db, "jarak (cm)"), function (snapshot) {
  const data = snapshot.val();
  cm.innerHTML = data;
});

onValue(ref(db, "jarak (inch)"), function (snapshot) {
  const data = snapshot.val();
  inch.innerHTML = data;
});

let lampState = false;
const btn = document.getElementById("btn");

let i = 0
btn.onclick = function () {
  i++
  if (lampState) {
    btn.innerHTML = "hidupkan lampu";
    lampState = !lampState;
    writeDB("lamp/"+i,false)
  } else {
    btn.innerHTML = "matikan lampu";
    lampState = !lampState;
    writeDB("lamp/"+i,true)
  }
};

