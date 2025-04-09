import fetch from 'node-fetch';

async function testWeather(city) {
    const payload = {
        id: "1",
        tool: "getWeatherDataByCityName",
        input: { city }
    };

    const res = await fetch('http://localhost:3000/mcp', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(payload)
    });

    const result = await res.json();
    console.log(`Weather for ${city}:`, JSON.stringify(result, null, 2));
}

testWeather("Patiala");
testWeather("Delhi");
testWeather("Kolkata");
