# Deceit Board

Deceit Board is a physical device intercepting the signal between keyboard and computer. By adding delays and spoof signals, it anonymises your unique typing pattern, rendering it useless for data collectors.

## How it works

The deceit board (in its first iteration) uses a [Teensy](https://www.pjrc.com/store/teensy32.html) board running Arduino code and a [PS/2 keyboard input](https://www.adafruit.com/products/1136). It receives and processes signals from an external keyboard before it passes them on to the computer. 


![Deceit Board](https://github.com/leoneckert/deceit-board/blob/master/deceit_board.jpg)

## The program

[as of 1/18/2016]<br>I tried different options for the program running on the teensy and of course it is still not finalised. The most effective one so far has been to make the board send keystrokes to the computer every 10 milli seconds. Those keystrokes are either one the user actually typed (retrieved from an array in which they are stored) or a spoof keystroke (I used caps lock on and off in quick succession). 
This results in an even typing rhythm with a 10 milli seconds break between any two keystrokes (subject to CPU clock precision) that reach the computer. This pattern is the same, no matter who is typing and therefore useless for collectors. 

## Testing

![Double Keyboard](https://github.com/leoneckert/deceit-board/blob/master/double_keyboard.jpg)

I used my own visualisation tools and a keyboard connected to two computers at the same time (shown in image above). One connection is intercepted by the deceit board, the other one is not filtered. The video below (click screenshot) shows the outcome of this experiment.

<a href="http://www.youtube.com/watch?feature=player_embedded&v=zoQVb48ETjI" target="_blank"><img src="https://github.com/leoneckert/deceit-board/blob/master/testing.png" 
alt="testing" width="700" height="398" border="10" /></a>

## To Do

* Use deceit board to imitate someone's keystroke pattern.
* [Behaviosec's demo](http://www.behaviosec.com/demos/) is a good place to test out things (like spoofing and defeating their algorithm).


## FAQ

Will the deceit board save our privacy once and for all?

>Absolutely not. As technology progresses, there is never one definite protection from surveillance that can not be broken soon. Above that, obviously, behavioural keyboard typing surveillance is just a tiny piece of the bigger picture.

Did someone do something similar (to the deceit board) before?

>Yes, there is a [Chrome plugin](https://chrome.google.com/webstore/detail/keyboard-privacy/aoeboeflhhnobfjkafamelopfeojdohk). The reason I decided to make a physical device is that inside our computer there is little a data collector could not somehow get hold of. The idea was to create a protection device that anonymises data before it reaches your computer altogether.

## Thanks

This project would not exist without the help of [Adam Harvey](https://ahprojects.com).

Thanks also to the Author of [this instructables](http://www.instructables.com/id/DOUBLE-KEYBOARD/).
