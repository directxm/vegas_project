
var NetLayer = cc.Layer.extend({
    sprite:null,
    socket:null,
    helloLabel:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        /////////////////////////////
        // 2. add a menu item with "X" image, which is clicked to quit the program
        //    you may modify it.
        // ask the window size
        var size = cc.winSize;

        /////////////////////////////
        // 3. add your codes below...
        // add a label shows "Hello World"
        // create and initialize a label
        helloLabel = new cc.LabelTTF("Test", "Arial", 38);
        // position the label on the center of the screen
        helloLabel.x = size.width / 2;
        helloLabel.y = size.height / 2 + 200;
        // add the label as a child to this layer
        this.addChild(helloLabel, 5);

        // add "HelloWorld" splash screen"
        /*this.sprite = new cc.Sprite(res.HelloWorld_png);
        this.sprite.attr({
            x: size.width / 2,
            y: size.height / 2
        });
        this.addChild(this.sprite, 0);*/

        // socket.io
        /*socket = io.connect('http://localhost:9092');

        socket.on('connect', function(){
            cc.log("connect");
        });
        socket.on('chatevent', function(data) {
            cc.log("chatevent" + data);
            helloLabel.setString("chatevent" + data)
        });
        socket.on('disconnect', function() {
            cc.log("disconnect");
        });
        socket.on("message", function(data) {
            cc.log("message received: " + data);
        });
        socket.on("error", function() {
            log("error called..");
        });

        socket.emit('chatevent', {userName:'111',message:'ssssssss'});*/

        // orgrion
        /*socket = new WebSocket("ws://localhost/game");
        socket.onopen = function() {
            cc.log("Welcome!");
            helloLabel.setString("Welcome!");
        };
        socket.onmessage = function(evt) {
            var data = JSON.parse(evt.data);
            cc.log("message");
            helloLabel.setString("message!");
        };
        socket.onclose = function(evt) {
            // See http://tools.ietf.org/html/rfc6455#section-7.4.1
            if (event.code == 1000)
                reason = "Normal closure, meaning that the purpose for which the connection was established has been fulfilled.";
            else if(event.code == 1001)
                reason = "An endpoint is \"going away\", such as a server going down or a browser having navigated away from a page.";
            else if(event.code == 1002)
                reason = "An endpoint is terminating the connection due to a protocol error";
            else if(event.code == 1003)
                reason = "An endpoint is terminating the connection because it has received a type of data it cannot accept (e.g., an endpoint that understands only text data MAY send this if it receives a binary message).";
            else if(event.code == 1004)
                reason = "Reserved. The specific meaning might be defined in the future.";
            else if(event.code == 1005)
                reason = "No status code was actually present.";
            else if(event.code == 1006)
                reason = "The connection was closed abnormally, e.g., without sending or receiving a Close control frame";
            else if(event.code == 1007)
                reason = "An endpoint is terminating the connection because it has received data within a message that was not consistent with the type of the message (e.g., non-UTF-8 [http://tools.ietf.org/html/rfc3629] data within a text message).";
            else if(event.code == 1008)
                reason = "An endpoint is terminating the connection because it has received a message that \"violates its policy\". This reason is given either if there is no other sutible reason, or if there is a need to hide specific details about the policy.";
            else if(event.code == 1009)
                reason = "An endpoint is terminating the connection because it has received a message that is too big for it to process.";
            else if(event.code == 1010) // Note that this status code is not used by the server, because it can fail the WebSocket handshake instead.
                reason = "An endpoint (client) is terminating the connection because it has expected the server to negotiate one or more extension, but the server didn't return them in the response message of the WebSocket handshake. <br /> Specifically, the extensions that are needed are: " + event.reason;
            else if(event.code == 1011)
                reason = "A server is terminating the connection because it encountered an unexpected condition that prevented it from fulfilling the request.";
            else if(event.code == 1015)
                reason = "The connection was closed due to a failure to perform a TLS handshake (e.g., the server certificate can't be verified).";
            else
                reason = "Unknown reason";

            cc.log("Close! " + reason);
            helloLabel.setString("Close! " + reason);
        }
        socket.onerror = function(evt) {
            cc.log("ERROR! " + reason);
            helloLabel.setString("ERROR! " + reason);
        }*/


        // atmosphere
        /*socket = atmosphere;
        var subSocket;
        var transport = 'websocket';

        var request = { url: "http://localhost/chat",
            contentType : "application/json",
            trackMessageLength : true,
            shared : true,
            transport : transport ,
            fallbackTransport: "long-polling"};

        request.onOpen = function(response) {

        }

        request.onTransportFailure = function(errorMsg, request) {

            if (window.EventSource) {
                request.fallbackTransport = "sse";
                transport = "see";
            }
        }

        request.onMessage = function (response) {

        }

        request.onClose = function(response) {

        }

        subSocket = socket.subscribe(request);*/




        return true;
    }
});

var NetScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new NetLayer();
        this.addChild(layer);
    }
});

