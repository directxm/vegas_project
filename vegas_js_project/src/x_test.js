
var sineEaseInOut = function (time) {
    return -0.5 * (Math.cos(3.14159265358979323846 * time - 1));
}

var XLayer = cc.Layer.extend({
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

        //var slot = new cc.Sprite("res/game.png");
        //this.addChild(slot, 9998);

        cc.spriteFrameCache.addSpriteFrames("res/game.plist");
        //cc.textureCache.addImage("res/game.png");

        //CCPointArray * array = CCPointArray::create(20);
        var slots = new Array();

        var STAR_POS_X = 200;
        var STAR_POS_Y = 100;

        for (var i = 0; i < 6; ++i)
        {
            var slot = new cc.Sprite("#item_2_30.png");
            slot.setScale(0.25);
            //slot->setOpacity(0.0f);
            var s = slot.getContentSize();
            var x = STAR_POS_X;
            var y = STAR_POS_Y + i * (s.height * slot.getScale());
            slot.setPosition(x, y);
            this.addChild(slot, 9998);

            //array->addControlPoint(slot->getPosition());

            var spark = new cc.Sprite("#symbol_border.png");
            spark.setScale(0.25);
            spark.setOpacity(0.0);
            spark.setPosition(x, y);
            this.addChild(spark, 9999);
            slots.push(spark);
        }

        for (var i = 0; i < 6; ++i)
        {
            var slot = new cc.Sprite("#item_2_30.png");
            slot.setScale(0.25);
            //slot->setOpacity(0.0f);
            var s = slot.getContentSize();
            var x = STAR_POS_X + (i + 1) * (s.width * slot.getScale());
            var y = STAR_POS_Y + 5 * (s.height * slot.getScale());
            slot.setPosition(x, y);
            this.addChild(slot, 9998);

            //array->addControlPoint(slot->getPosition());

            var spark = new cc.Sprite("#symbol_border.png");
            spark.setScale(0.25);
            spark.setOpacity(0.0);
            spark.setPosition(x, y);
            this.addChild(spark, 9999);
            slots.push(spark);
        }

        for (var i = 5; i >= 0; --i)
        {
            var slot = new cc.Sprite("#item_2_30.png");
            slot.setScale(0.25);
            //slot->setOpacity(0.0f);
            var s = slot.getContentSize();
            var x = STAR_POS_X + 6 * (s.width * slot.getScale());
            var y = STAR_POS_Y + i * (s.height * slot.getScale());
            slot.setPosition(x, y);
            this.addChild(slot, 9998);

            //array->addControlPoint(slot->getPosition());

            var spark = new cc.Sprite("#symbol_border.png");
            spark.setScale(0.25);
            spark.setOpacity(0.0);
            spark.setPosition(x, y);
            this.addChild(spark, 9999);
            slots.push(spark);
        }

        for (var i = 5; i >= 0; --i)
        {
            var slot = new cc.Sprite("#item_2_30.png");
            slot.setScale(0.25);
            //slot->setOpacity(0.0f);
            var s = slot.getContentSize();
            var x = STAR_POS_X + (i + 1) * (s.width * slot.getScale());
            var y = STAR_POS_Y;
            slot.setPosition(x, y);
            this.addChild(slot, 9998);

            //array->addControlPoint(slot->getPosition());

            var spark = new cc.Sprite("#symbol_border.png");
            spark.setScale(0.25);
            spark.setOpacity(0.0);
            spark.setPosition(x, y);
            this.addChild(spark, 9999);
            slots.push(spark);
        }

        var source = 12;
        var target = 10;

        var count = (slots.length - source) + slots.length * 3 + target;
        var rate = 2.0 / count;
        for (var i = source; i <= count; ++i)
        {
            var sp = slots[i % slots.length];
            if (sp != undefined)
            {
                var delta = rate * i;
                var time = (i - source + 1) * 0.1 + 1.0 - sineEaseInOut(delta);
                var predelay = cc.delayTime(time);
                //log("delay index %d delta %f time  %f", i, delta, time);
                var fadein = cc.fadeIn(1);
                //CCActionInterval* delaytime = CCDelayTime::create(0.2);
                var fadeout = cc.fadeOut(1);

                //CCFiniteTimeAction* seq = CCSequence::create(predelay, fadein, delaytime, fadeout, nullptr);
                var seq = undefined;
                if (i == count)
                {
                    seq = cc.sequence(predelay, fadein);
                }
                else
                {
                    seq = cc.sequence(predelay, fadein, fadeout);
                }

                //CCFiniteTimeAction* repeat = CCRepeat::create(seq, 3);
                //seq->setTarget(sp);
                if (seq != undefined)
                {
                    sp.runAction(seq);
                }
            }
        }

        return true;
    }
});

var XScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new XLayer();
        this.addChild(layer);
    }
});

