# Deceit Board

Deceit Board is a physical device intercepting the signal between keyboard and computer. By adding delays and spoof signals, it anonymises your unique typing pattern, rendering it useless for data collectors.

## How it works

The deceit board (in its first iteration) uses a Teensy board running Arduino code and a ps/2 keyboard input. It receives and processes signals from an external keyboard before it passes them on to the computer. 


![Deceit Board](https://github.com/leoneckert/deceit-board/blob/master/deceit_board.jpg)

## The program

I tried different options for the program running on the teensy, and of course it is still not finalised. The most effective one so far has been to make the board send keystrokes to the computer every 10 milli seconds. Those keystrokes are either one the user actually typed (retrieved from an array in which they are stored) or a spoof keystroke (I used caps lock on and off in quick succession). 
This results in a even typing rhythm with a 10 milli seconds break between any two keystrokes (subject to CPU clock precision) that reach the computer. This pattern is the same, no matter who is typing and therefore useless for collectors. 

## Testing

## To Do

## FAQ

## Thanks

I received amazing help from [Adam Harvey](https://ahprojects.com).

Thanks also to the Author of [this instructables](http://www.instructables.com/id/DOUBLE-KEYBOARD/).
