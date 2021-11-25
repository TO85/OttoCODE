# Best Practices

&bigtriangleup; **Top**[Main](../Main.md) &CenterDot; &blacktriangle; Up &CenterDot; &blacktriangleleft; Previous &CenterDot; &blacktriangledown; First &CenterDot; &blacktriangleright; Next 


## Public Projects

* [OpenCV's Style Guide](https://github.com/opencv/opencv/wiki/Coding_Style_Guide) is a good starting point.


## SOLID



### Interface



* Use many smaller interfaces rather than one huge one.
  * Also supports practice than any class should only do one thing.
* Interfaces directory

### Dependency Inversion

* Avoid mixing dependency and interfaces
  * See above with many interfaces that only do one thing

KISS - Keep It Simple Stupid

DRY - Don't Repeat Yourself

See https://www.udemy.com/course/qt-5-design-patterns/learn/lecture/21870776#questions  #22 for Listening TCP socket in main outside of QApplication.

Encapsulate data access in class wrapper.



## Qt

### QObject

* You can't copy a QObject descendent
* _But, you can clone() one_
* Do NOT deletelater() on stack objects
* qDeleteAll(list) - frees pointers in list, but still list.clear() so you don't have dangleng pointers to use by mistake



