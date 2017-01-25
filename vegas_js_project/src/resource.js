var res = {
    HelloWorld_png : "res/HelloWorld.png",
    //Test_ccbi : "res/ccbi/Published-HTML5/MainScene.ccbi",
    game_pls : "res/game.plist",
    game_png : "res/game.png",
};

var g_resources = [
    res.game_pls,
    res.game_png,
];

for (var i in res) {
    g_resources.push(res[i]);
}
