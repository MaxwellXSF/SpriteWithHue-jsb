/**
 * Created by Maxwell on 15-10-28.
 */
var JSBSpriteWithHue = function(parent)
{
    //CCSpriteWithHue 图片
    for(var m=0; m<30; m++)
    {
        var sprite = sj.SpriteWithHue.create("res/alien.png");
        sprite.setPosition(900 * Math.random(),640 * Math.random());
        sprite.setHue(2 * Math.PI * Math.random());
        parent.addChild(sprite);
    }

    //CCSpriteWithHue 动画
    cc.spriteFrameCache.addSpriteFrames("res/grossini-aliases.plist");
    for (var i=0; i<30; i++) {

        var animFrames = [];
        var str = "";
        var frame;
        for (var j = 1; j < 15; j++) {
            str = "grossini_dance_" + (j < 10 ? ("0" + j) : j) + ".png";
            frame = cc.spriteFrameCache.getSpriteFrame(str);
            animFrames.push(frame);
        }

        var animation = new cc.Animation(animFrames, 0.3);

        var sprite = sj.SpriteWithHue.createWithSpriteFrameName("grossini_dance_01.png");
        //var sprite = new cc.Sprite("#grossini_dance_01.png");
        sprite.setPosition(960 * Math.random(),640 * Math.random());
        sprite.setHue(2 * Math.PI * Math.random());
        sprite.runAction(cc.animate(animation).repeatForever());

        parent.addChild(sprite);
    }
};
