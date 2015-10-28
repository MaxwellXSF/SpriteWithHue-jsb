/**
 * Created by Maxwell on 15-10-27.
 */
var Example = cc.Scene.extend({
    onEnter:function () {
        this._super();
        //test
        new JSBTest();
        //SpriteWithHue
        new JSBSpriteWithHue(this);
    }
});