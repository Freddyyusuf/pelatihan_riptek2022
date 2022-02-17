import { initializeApp } from "https://www.gstatic.com/firebasejs/9.6.6/firebase-app.js";
import { getDatabase, ref, set, onValue } from "https://www.gstatic.com/firebasejs/9.6.6/firebase-database.js";
 
const firebaseConfig = {
    apiKey: "",
    authDomain: "",
    projectId: "",
    storageBucket: "",
    messagingSenderId: "",
    appId: "",
    databaseURL: ""
};
 
const app = initializeApp(firebaseConfig);
const db = getDatabase(app)
 
function writeDB(key, value) {
    set(ref(db, key), value);
}
 
const temperature = document.getElementById("temperature")
const submitBtn = document.getElementById("submitBtn")
 
submitBtn.onclick = function() {
    writeDB("temperature", temperature.value)
}
 
const kelembaban = document.getElementById("kelembaban")
 
onValue(ref(db, "humidity"), function(snapshot) {
    const data = snapshot.val();
    kelembaban.innerHTML = data
});