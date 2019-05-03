import nexmo

client = nexmo.Client(key="******", secret="***********")

client.send_message({
    'from': "Nexmo",
    'to': "***********",
    'text': "Hello from Nexmo",
})
