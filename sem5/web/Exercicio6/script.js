var color = document.getElementById("color")
var colorHex = document.getElementById("colorHex")
var colorName = document.getElementById("colorName")
var buttomPromise = document.getElementById("changeColorPromise")
var buttomAwaitAsync = document.getElementById("changeColorAwaitAsync")

function requestColor(color) 
{
    return new Promise(function(resolve, reject) {
        let ajax = new XMLHttpRequest();
        ajax.open("GET", "https://reqres.in/api/unknown/" + color)
        ajax.onload = function() 
        {
            if(ajax.status == 200){
                let response = JSON.parse(this.responseText)    
                resolve({hexColor: response.data.color, nameColor:response.data.name});
            }else{
                reject("Color not available");
            }
        };
        ajax.onerror = function() 
        {
            reject("Color not available")
        };
        ajax.send();
    });
}

buttomPromise.addEventListener("click", (_) => {
    let id = document.getElementById("colorID").value
    let resultColor = requestColor(id)
    resultColor.then((result) => {
        color.style.backgroundColor = result.hexColor
        colorHex.innerHTML = result.hexColor
        colorName.innerHTML = result.nameColor
    }).catch((error) => {
        alert(error)
    })
})

function isJoeHappy(happy, callback) 
{
    setTimeout(() => {
        const happyness = Math.random()
        if (happyness > happy) {
            callback(happyness);
        } else {
            callback(new Error("Joe is sad!"));
        }
    }, 2000);
}

function isJoeHappyPromise(happy) 
{
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            const happyness = Math.random()
            if (happyness > happy) {
                return resolve(happyness);
            } 

            return reject(new Error("Joe is sad!"));
        }, 2000);
    })
}

async function isJoeHappyPromiseAsync(happy) 
{
    try{
        await new Promise(resolve => setTimeout(resolve, 2000));
        const happyness = Math.random()
        if (happyness > happy) {
            return happyness;
        } else {
            throw new Error("Joe is sad!");
        }
    } catch(error){
        return error
    }
}

var joeButtom = document.getElementById("joeButton")
var joeOutput = document.getElementById("joeOutput")
var version = 0; // used to call the 3 versions of the function each time 

joeButtom.addEventListener("click", async (_) => {
    let threshold = document.getElementById("thresholdInput")
    if(threshold.value < 0 || threshold.value > 1){
        threshold.style.borderColor = "red"
        joeOutput.innerHTML = ""
    }else{
        threshold.style.borderColor = "black"
        if(version % 3 == 0){
            alert("Callback function")
            isJoeHappy(threshold.value, (happiness) => {
                if(happiness instanceof Error){
                    joeOutput.innerHTML = "No ! ! ! " + happiness.message
                    joeOutput.style.color = "red"
                }else{
                    joeOutput.innerHTML = "Yes! By " +  Math.round(happiness * 100) + "%"
                    joeOutput.style.color = "black"
                }
            })
        }else if(version % 3 == 1){
            alert("Promise function")
            const promise = isJoeHappyPromise(threshold.value)
            promise.then((happiness) => {
                joeOutput.style.color = "black"
                joeOutput.innerHTML = "Yes! By " +  Math.round(happiness * 100) + "%"
            }).catch((error) => {
                joeOutput.style.color = "red" 
                joeOutput.innerHTML = "No ! ! ! " + error.message
            })
        }else{
            alert("Async/Await")
            const asyncResponse = await isJoeHappyPromiseAsync(threshold.value)
            if(asyncResponse instanceof Error){
                joeOutput.style.color = "red"
                joeOutput.innerHTML = "No ! ! ! " + asyncResponse.message
            }else{
                joeOutput.style.color = "black"
                joeOutput.innerHTML = "Yes! By " +  Math.round(asyncResponse * 100) + "%"
            }
        }
        version++;
    }
})

async function awaitColorRequest() 
{
    let id = document.getElementById("colorID").value
    let result = await requestColor(id)
    if(result instanceof String){
        alert(result)
    }else{
        color.style.backgroundColor = result.hexColor
        colorHex.innerHTML = result.hexColor
        colorName.innerHTML = result.nameColor
    }
}

buttomAwaitAsync.addEventListener("click", async (_) => {
    await awaitColorRequest()
})