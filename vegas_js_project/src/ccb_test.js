/**
 * Created by fatum on 2016/11/29.
 */

// 这是一个父类
var BaseLayer = cc.Layer.extend({
    // 加载cbbi文件 并添加到当前蹭上
    loadCCB:function(ccbFileName,ccbFilePath){
        cc.BuilderReader.registerController(ccbFileName, this);
        cc.BuilderReader.setResourcePath("res/ccbi/Published-HTML5/");
        var node = cc.BuilderReader.load(ccbFilePath, this);
        this.addChild(node);
    },

    // 通过上边引擎代码的修改，当播放完动画之后会回调本方法，参数是播放完的动画的名字
    completedAnimationSequenceNamed:function(animationName){
        cc.log(animationName + "动画播放完毕");
    },

    // 加载完ccbi会调用此方法
    onDidLoadFromCCB:function(ccbFileName){
        cc.log(ccbFileName + "加载完毕");
        //this.helloLabel.setText(ccbFileName + "加载完毕");
    },

    onPressButton:function() {
        // Rotate the label when the button is pressed
        this.helloLabel.runAction(cc.RotateBy.create(1, 360));

    },


});

// 刚才的ccbi文件会绑定到当前这个层上
var TestSceneLayer = BaseLayer.extend({

    // 重写父类的方法 已处理自己播放完动画要做的事情
    completedAnimationSequenceNamed:function(animationName){
        cc.log(animationName + "动画播放完毕");

        if(animationName == "action"){
            //o nTest是本层的一个测试方法 证明当前的this 就是 本层的this
            this.onTest();
        }

    },

    // ccbi里边按钮的回调方法 同过对引擎的修改 只要本层写了这个方法 并且名字和ccbi里边的一样 就能直接绑定上不需要其他做
    onPressButton:function(sender){
        cc.log("MainSceneLayer.ctor() "+sender.getTag() + this._item);
        // 播放动画 ccbi里边我创建了一个名字叫action的时间线
        //this.rootNode.animationManager.runAnimationsForSequenceNamed("action");
        this.helloLabel.setString("fuck");
    },

    onTest:function(){
        // helloLabel是ccbi里边的一个LabelTTF 名字就叫helloLabel 通过this.可以直接获取 已经绑定好了 无需其他操作
        this.helloLabel.setString("nimeide");
    }
});


var TestScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new TestSceneLayer();
        // 第一个参数是你的ccbi的JS Controller 的值
        // 第二个参数是你的.ccbi文件的路径
        layer.loadCCB("MainScene", res.Test_ccbi);

        this.addChild(layer);
    }
});