/**
 * Created by Maxwell on 15-10-27.
 */

var JSBTest = cc.Layer.extend({
    ctor:function () {
        var test =new sj.Test();
        cc.log(test.funcTest());
        test.argcTest(1);
    }
});


var Example = cc.Scene.extend({
    onEnter:function () {
        this._super();

        //test
        new JSBTest();

        //CCSpriteWithHue
        for(var i=0; i<30; i++)
        {
            var sprite = sj.SpriteWithHue.create("res/alien.png");
            sprite.setPosition(900 * Math.random(),640 * Math.random());
            sprite.setHue(2 * Math.PI * Math.random());
            this.addChild(sprite);
        }
//    cc.spriteFrameCache.addSpriteFrames("res/grossini-aliases.plist","res/grossini-aliases.png");
//    for (var i=0; i<30; i++) {
//        var frame = [];
//        for(var j = 0 ; i < 15 ; j++)
//        {
//            var name = "dance_" + j;
//            var sigle = cc.spriteFrameCache.getSpriteFrame(name);
//            frame.push(sigle);
//        }

//        var animation = new cc.Animation(frame,0.3);
//
//        var sprite = sj.SpriteWithHue.createWithSpriteFrameName("res/grossini_dance_01.png");
//        sprite.setPosition(960 * Math.random(),640 * Math.random());
//        sprite.setHue(2 * Math.PI * Math.random());
//        sprite.runAction(new cc.RepeatForever(cc.Animate(animation)));
//
//        scene.addChild(sprite);
//    }
    }
});