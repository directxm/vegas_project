/**
 * Created by fatum on 2017/1/16.
 */

var SlotType = {};
SlotType.None = -1;
SlotType.Orange = 0;
SlotType.OrangeX2 = 2;
SlotType.Bell = 3;
SlotType.BellX2 = 4;
SlotType.BarX50 = 5;
SlotType.BarX25 = 6;
SlotType.Apple = 7;
SlotType.AppleX2 = 8;
SlotType.Star = 9;
SlotType.StarX2 = 10;
SlotType.GoodLuck1 = 11;
SlotType.GoodLuck2 = 12;
SlotType.HamiMelon = 13;
SlotType.HamiMelonX2 = 14;
SlotType.WaterMelon = 15;
SlotType.WaterMelonX2 = 16;
SlotType.Number77 = 17;
SlotType.Number77X2 = 18;
SlotType.MAX = 18;

var SlotType2 = {};
SlotType2.Orange = 0;
SlotType2.Bell = 3;
SlotType2.Bar = 5;
SlotType2.Apple = 7;
SlotType2.Star = 9;
SlotType2.GoodLuck = 11;
SlotType2.HamiMelon = 13;
SlotType2.WaterMelon = 15;
SlotType2.Number77 = 17;

var LosePercentType = {};
LosePercentType.Percent10 = 0;
LosePercentType.Percent50 = 1;
LosePercentType.Percent100 = 2;

var PuzzleType = {};
PuzzleType.Big = 0;
PuzzleType.Small = 1;

var GameStatus = {};
GameStatus.Wait = 0;
GameStatus.CountDownLottery = 1;
GameStatus.Lottery = 2;
GameStatus.CountDownPuzzle = 3;
GameStatus.Puzzle = 4;
GameStatus.Prize = 5;


var FruitMachineScene = function () {
    this._mid = 0;

    this._status = GameStatus.Wait;
    this._currentBettingValues = {};
    this._previousBettingValues = {};
    this._slotTotalBettingValues = {};
    this._puzzleType = undefined;

    this._sourceSlot = SlotType.None;
    this._targetSlot = SlotType.None;
    this._luckyPrize = new Array();
    this._rewardValue = 0;
    this._targetPuzzleType = undefined;

    this._losePercent = LosePercentType.Percent10;
    this._countDownTime = 0;
    this._money = 0;
    this._poolMoney = 0;

    // UI
    this._slots = new Array();

}

FruitMachineScene.prototype.onDidLoadFromCCB = function () {
    this.startup();

}

FruitMachineScene.prototype.startup = function () {
    this._status = GameStatus.CountDownLottery;

    // initialize
    this._mid = 100000002220;
    this._poolMoney = 50000;
    this._money = 300;

    this.rootNode.schedule(this.rootNode.onUpdate);
}

FruitMachineScene.prototype.onPressBetting = function (sender) {
    if (this.canBet())
    {
        this.bet(SlotType2.Orange);
    }
}

/*FruitMachineScene.prototype.onPressBetting2 = function (sender) {

}

FruitMachineScene.prototype.onPressBetting3 = function (sender) {

}

FruitMachineScene.prototype.onPressBetting4 = function (sender) {

}

FruitMachineScene.prototype.onPressBetting5 = function (sender) {

}

FruitMachineScene.prototype.onPressBetting6 = function (sender) {

}

FruitMachineScene.prototype.onPressBetting7 = function (sender) {

}

FruitMachineScene.prototype.onPressBetting8 = function (sender) {

}*/

FruitMachineScene.prototype.onPressPreviousBet = function () {
    if (this.canBet() && this._previousBettingValues != undefined)
    {
        this._previousBettingValues = undefined;
        // ui disabled
        this._previousBetButton.enable = false;
    }
}

FruitMachineScene.prototype.onPressPuzzle = function (type) {
    if (this.canPuzzle())
    {
        if (type == PuzzleType.Big)
        {
            this._bigPuzzleButton.enable = true;
            this._smallPuzzleButton.enable = false;
            this._puzzleType = PuzzleType.Big;
        }
        else
        {
            this._bigPuzzleButton.enable = false;
            this._smallPuzzleButton.enable = true;
            this._puzzleType = PuzzleType.Small;
        }
    }
}

FruitMachineScene.prototype.onPressLosePercent = function (type) {
    if (this.canBet())
    {
        this._losePercent = LosePercentType.Percent10;
        this._losePercentLable.setString(this._losePercent);
    }
}

FruitMachineScene.prototype.setStatus = function (status) {
    this._status = status;
}

FruitMachineScene.prototype.bet = function (type) {
    var value = this._slotBettingValues[type] + (1 * this._losePercent);
    this._slotBettingValues[type] = value;
    this._slotBettingValueLables[type].setString(value);
    /*if (this.canBet())
    {

    }*/
}

FruitMachineScene.prototype.puzzle = function (type) {
    this._puzzleType = type;
    if (this._puzzleType == PuzzleType.Big)
    {
        this._puzzleTypeButton[PuzzleType.Big].enable = true;
        this._puzzleTypeButton[PuzzleType.Small].enable = false;
    }
    else
    {
        this._puzzleTypeButton[PuzzleType.Big].enable = false;
        this._puzzleTypeButton[PuzzleType.Small].enable = true;
    }
    //this._slotBettingValueLables[type].setString(value);
    /*if (this.canPuzzle())
    {

    }*/
}

FruitMachineScene.prototype.canBet = function() { return this._status == GameStatus.CountDownLottery; }
FruitMachineScene.prototype.canPuzzle = function() { return this._status == GameStatus.CountDownPuzzle; }
//FruitMachineScene.prototype.bingoLottery = function() { return this._slotBettingValues[this._targetSlot] != 0; }
//FruitMachineScene.prototype.bingoPuzzle = function() { return this._slotBettingValues[this._targetSlot] != 0; }

FruitMachineScene.prototype.onUpdate = function (dt) {
    this.updateCountDownLottery(dt);
    this.updateCountDownPuzzle(dt);
    this.updatePrize(dt);


    /*if (this._status == GameStatus.CountDownLottery)
    {

    }
    else if (this._status == GameStatus.Lottery)
    {

    }
    else if (this._status == GameStatus.CountDownPuzzle)
    {

    }
    else if (this._status == GameStatus.Puzzle)
    {

    }
    else if (this._status == GameStatus.Prize)
    {

    }*/

    //this._countDownTime += dt;
}

FruitMachineScene.prototype.drawLottery = function() {

    var count = (this._slots.length - this._sourceSlot) + this._slots.length * 3 + this._targetSlot;
    var rate = 2.0 / count;
    for (var i = this._sourceSlot; i <= count; ++i)
    {
        var sp = this._slots[i % this._slots.length];
        if (sp != undefined)
        {
            var delta = rate * i;
            var time = (i - this._sourceSlot + 1) * 0.1 + 1.0 - sineEaseInOut(delta);
            var predelay = cc.delayTime(time);
            //log("delay index %d delta %f time  %f", i, delta, time);
            var fadein = cc.fadeIn(1);
            //CCActionInterval* delaytime = CCDelayTime::create(0.2);
            var fadeout = cc.fadeOut(1);

            //CCFiniteTimeAction* seq = CCSequence::create(predelay, fadein, delaytime, fadeout, nullptr);
            var seq = undefined;
            if (i == count)
            {
                seq = cc.sequence(predelay, fadein, cc.callFunc(this.endLottery, this));
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
}

FruitMachineScene.prototype.endLottery = function() {

    if (this._luckyPrize != undefined && this._luckyPrize.length != 0) {
        //this.onPrize();
        this.drawLucky();
    }
    else if (this._rewardValue > 0) // bingo
    {
        // ui
        this._rewardLable.setString(this._rewardValue);
        this.onPuzzle();
    }
    else {
        this.setStatus(GameStatus.CountDownLottery);
    }
    //setState();
}

FruitMachineScene.prototype.drawLucky = function () {
    //var array = new Array();
    var time = 0;
    for (var i = 0; i < this._luckyPrize.length; ++i) {
        var count = (this._slots.length - this._targetSlot) + this._luckyPrize[i];

        for (var j = this._sourceSlot; j <= count; ++j) {

            var sp = this._slots[j % this._slots.length];
            if (sp != undefined) {

                var predelay = cc.delayTime(time);
                //log("delay index %d delta %f time  %f", i, delta, time);
                var fadein = cc.fadeIn(1);
                //CCActionInterval* delaytime = CCDelayTime::create(0.2);
                var fadeout = cc.fadeOut(1);



            }

        }

    }
    //array.push(cc.callFunc(this.endLucky, this))

}

FruitMachineScene.prototype.endLucky = function () {
    this._luckyPrize = undefined;
    if (this._rewardValue > 0) // bingo
    {
        // ui
        this._rewardLable.setString(this._rewardValue);
        this.onPuzzle();
    }
    else {
        this.setStatus(GameStatus.CountDownLottery);
    }
}

FruitMachineScene.prototype.drawPuzzle = function() {
    // to display is big or small

}

FruitMachineScene.prototype.endPuzzle = function() {
    if (this._rewardValue == 0) {
        this._status = GameStatus.CountDownLottery;
    }
    else {
        this.onPrize();
    }

    // ui reset

}

FruitMachineScene.prototype.drawPrize = function () {

    if (this._rewardValue > 0) // n seconds jump a number
    {
        this._moneyLable.setString(++this._money);
        --this._rewardValue;
    }
    else {
        this.endPrize();
    }

}

FruitMachineScene.prototype.endPrize = function () {
    this._status = GameStatus.CountDownLottery;
}

FruitMachineScene.prototype.updateCountDownLottery = function (delta) {

    if (this._status == GameStatus.CountDownLottery) {
        this._countDownTime += delta;

        var n = Math.ceil(this._countDownTime);
        // update count ui
        this._lotteryCountDownLabel.setString(10 - n);

        if (n >= 10) {
            // lottery
            this.onLottery();
        }
    }
}

FruitMachineScene.prototype.updateCountDownPuzzle = function (delta) {

    if (this._status == GameStatus.CountDownPuzzle) {
        this._countDownTime += delta;

        // update count ui
        this._puzzleCountDownLabel.setString(10 - Math.ceil(this._countDownTime));

        // puzzle
        this.onPuzzle();
    }

}

/*FruitMachineScene.prototype.updatePrize = function (delta) {
    if (this._status == GameStatus.Prize)
    {
        this.onPrize();
    }
}*/

FruitMachineScene.prototype.onLottery = function () {

    // next status
    this._countDownTime = 0;
    this.setStatus(GameStatus.Lottery);
    this._currentBettingValues = [0, 0, 0, 0, 0, 0, 0, 0];
    this._previousBettingValues = this._currentBettingValues.slice();

    this._sourceSlot = this._targetSlot;
    this._targetSlot = Math.random() % SlotType.MAX;
    if (Math.random() % 10 > 5) {
        this._luckyPrize.push(Math.random() % SlotType.MAX);
        this._luckyPrize.push(Math.random() % SlotType.MAX);
        this._luckyPrize.push(Math.random() % SlotType.MAX);
    }

    // ui
    this.drawLottery();
}

FruitMachineScene.prototype.onPuzzle = function () {
    if (this._status == GameStatus.CountDownPuzzle && Math.ceil(this._countDownTime) >= 10) {
        this._targetPuzzleType = PuzzleType.Big;

        if (this._targetPuzzleType == this._puzzleType) {
            this.drawPuzzle();
        }
        else {
            this.endPuzzle();
        }

        return true;
    }
    return false;
}

FruitMachineScene.prototype.onPrize = function () {
    // next status
    this.setStatus(GameStatus.Prize);

    this.drawPrize();

}