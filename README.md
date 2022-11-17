# SNAKE
- A [SNAKE](https://github.com/xhf-F/Simple_Game--SNAKE) game written in c++
- This is a simple SNAKE game. You will start from the center with the snake head - "0". Then if you successfully get one fruit - "\*", your tail - "o" will add one following the head. Next, if you get one fruit again, your new one tail will be added from the end.
- Rule: 
  - Control key:
    - UP   :  i/I
    - DOWN :  k/K
    - LEFT :  j/J
    - RIGHT:  l/L
   - Start: press any key mentioned above
   - Exit: press q/Q/e/E
   - Gameover: The head hits your tails.
- You can directly download/run this [executable program](https://github.com/xhf-F/Simple_Game--SNAKE/raw/main/Simple_SNAKE).
- Brief exaplanation about the codes
  - Header: There are four basic functions to make this game run. They are ```Setup()``` for initializarion, ```Draw()``` for printing the "wall", "fruit" and "snake", ```Input()``` for inputting control commands, and ```Logic()``` for judgments on movings and scores in the ```.H``` file. And another one ```renew()``` just does for updating the position of fruits. 
  - Source: In the ```.cpp``` file, first it needs to setup and then goes into a ```while``` loop implementing other three basic functions in it. For a comfortable display, it includes a ```Linux```'s ```sleep()``` following the ```Draw()```. This is a testing file to some extent. 
- Makefile
  - Just simply apply: 
  ```
  $ make
  ``` 
  - in the command line then it will generate ```.o``` files and the executable program.
- code references 
  - [part 1](https://www.youtube.com/watch?v=E_-lMZDi7Uw)
  - [part 2](https://www.youtube.com/watch?v=W1e5wO7XR2w)
  - [part 3](https://www.youtube.com/watch?v=PSoLD9mVXTA)
