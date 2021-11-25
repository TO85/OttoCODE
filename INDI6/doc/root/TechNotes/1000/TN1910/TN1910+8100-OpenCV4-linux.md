# OpenCV4 - Linux Build

&bigtriangleup; **Top**  [Main](../Main.md) &CenterDot; &blacktriangle; **Up** [General](../General.md) &CenterDot; &blacktriangledown; **First**  &CenterDot; &blacktriangleleft; _Previous_ &CenterDot; &blacktriangleright; Next 

## Overview

To include OpenCV4 in Linux-based development projects, we download a snapshot of `github.com/opencv/opencv` master build (latest public release), unzip the snapshot, configure the build, and make the build.

## Reference

* [OpenCV Docs: Linux Install Tutorial](https://docs.opencv.org/4.5.2/d7/d9f/tutorial_install.html)

## Steps

### Setup 3rdParty Repository

* [x] Add `3rdParty` Repository under `github.com/TOtto-EclipseIR` account. Copy the clone HTTPS URL.

* [x] From `GitAhead`, Clone the 3rdParty Repository URL into `~dev/github/`

### Install tools

* From Terminal:

  * [x] In `~`, as needed
    * [x] `sudo apt update`
    * [x] `sudo apt install -y cmake cmake-gui`
      * [ ] $`cd /usr/share`
      * [ ] $`sudo chown -R :dev cmake-3.16/`
    * [x] `sudo apt install -y make`
    * [x] `sudo apt install -y g++`
    * [ ] `sudo apt install -y gdb gdb-doc`
    * [x] `sudo apt install -y wget`
    * [x] `sudo apt install -y unzip`
    * [ ] &iquest;IPPICV?
  
  
  
  ### Prerequisites
  
  #### Python3
  
  * Reference: [Ask Ubuntu](https://askubuntu.com/questions/1197683/how-do-i-install-python-3-8-in-lubuntu-18-04)
  * [x] $`sudo apt update`
  * [x] $`sudo apt install software-properties-common`
  * [x] $`sudo add-apt-repository ppa:deadsnakes/ppa`
  * [x] $`sudo apt install python3.9 (v3.9.6 2021-06-28) is latest)
  * [x] To Test: $`python3.9 --version`
  
  #### ZLib
  
  * Reference: [Ask Ubuntu](https://askubuntu.com/questions/743604/how-do-i-get-the-zlib-library-and-headers)
  * [ ] $ `sudo apt install zlib1g zlib1g-dev`
  
  #### JPEG
  
  * Reference: [Ask Ubuntu](https://askubuntu.com/questions/211627/how-to-add-support-for-the-jpeg-image-format)
  * [ ] $`sudo apt-get install build-essential checkinstall libx11-dev libxext-dev zlib1g-dev libjpeg-dev libfreetype6-dev libxml2-dev`
  
  #### libpng12-dev
  
  * [ ] $`sudo add-apt-repository ppa:linuxuprising/libpng12`
  * [ ] $`sudo apt update`
  * [ ] $`sudo apt install libpng12-0`
  
  #### TIFF
  
  Reference: [Ask Ubuntu](https://askubuntu.com/questions/44132/how-do-i-install-libtiff-so-3/815009#815009)
  
  * In ~/Downloads
  * From `http://download.osgeo.org/libtiff/` get v4.3.0 2021-Apr-20
  * [ ] $`wget http://download.osgeo.org/libtiff/tiff-4.3.0.zip`
  * [ ] $`unzip tiff-4.3.0.zip`
  * [ ] $`cd tiff-4.3.0`
  * [ ] $`./configure`
  * [ ] $`make`
  * [ ] $`sudo make install`
  
  #### Gimp (gegl & webp)
  
  * Reference: [Ask Ubuntu](https://askubuntu.com/questions/311651/how-to-install-webp-plugin-for-gimp): [Ask Ubuntu](https://askubuntu.com/questions/311651/how-to-install-webp-plugin-for-gimp)
  * [ ] $`sudo apt install ppa-purge && sudo ppa-purge ppa:otto-kesselgulasch/gimp`
  * [ ] $`sudo apt-get install build-essential git cmake libgimp2.0-dev libwebp-dev`
  
  * [ ] 
  * [ ] $`sudo apt-get install gimp`
  * [ ] 
  
  
  
  #### OpenGL
  
  * Reference: [Ask Ubuntu](https://askubuntu.com/questions/795647/how-to-install-opengl-4-0-or-4-5-for-developing)
  * [ ] $`sudo apt install libgl1-mesa-dev mesa-common-dev `
  * **Didn't help**
  * [x] Remove Entry `_qt5gui_OPENGL_INCLUDE)DIR`
  * [x] Uncheck `WITH_OPENGL`
  * [ ] [[Configure]]
  * Look for `Configuring done`
  * [ ] [[Generate]]
  * Look for `Generating done`
  
  
  
  ### Download Snapshot 
  
  * [x] In `~/Downloads`
    * [x] `wget -O opencv.zip https://github.com/opencv/opencv/archive/master.zip`
  
  ### CMake
  
  * [x] In `~dev/github/3rdParty`:
  
    * $`unzip ~/Downloads/opencv-master.zip`
    * [ ] $`mkdir ~dev/opencv-build`
    * [ ] Open cmake-gui: $`sudo /usr/bin/cmake-gui`
      * [ ] Source Code: `/home/dev/github/3rdParty/opencv-master`
      * [ ] Build Binaries: `/home/dev/opencv-build` 
      * [ ] [[Configure]]
        * [ ] Select: Unix Makefiles & Use default compilers
        * [ ] [[Finish]]
        * Look for ''Configuration done"
      * [ ] Check WITH_QT
      * [ ] [[Configure]]
      * [ ] Set QT5_DIR to `/opt/Qt/5/15.2/gcc_64/lib/cmake`
      * [ ] [[Configure]]
        * Look for ''Configuration done"
      * [ ] [[Generate]] 
        * Look for"Generation done"
    
    ### Build
    
    * While still in ~dev/github/3rdParty/opencv-build,
    * [ ] $`sudo make -j3`
    * **!COMPILE BROKEN!**: Exception building _gapi_ test module.
      * Reference: [OpenCV docs](https://docs.opencv.org/4.5.2/d0/d1e/gapi.html)
      * G_API _(Graph API)_ is acknowledged  by OpenCV maintainers as nearly experimental and not fitting into the normal algorithm template. We don't need it in the foreseeable future, so:
      * [ ] In **cmake-gui**, search for `GAPI` and disable building it for now.
        * [ ] Source: `~dev/github/3rdParty/opencv-master`
        * [ ] Destination: `~dev/opencv-build`
        * [ ] [[Configure]]
        * [ ] Default Native Compilers
        * [ ] [[Finish]]
        * [ ] Search: `GAPI`
        * [ ] Uncheck: `BUILD_opencv_gapi
        * [ ] [[Configure]]
          * Expect `Configuring done`
        * [ ] [[Generate]]
          * Expect `Generating done`
      * [ ] $`sudo make -j3` to finish build.
    * [ ] $`sudo make install`
    
    ### Git 3rdParty Repo
    
    * [ ] Commit any changes to `~dev/github/3rdParty/opencv`
    * [ ] Push to origin
    * [ ] Decide what to do with `opencv-build` directory
