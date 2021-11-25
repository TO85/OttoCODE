# Alpha1

## File Setup

Copy the INDIface directory and all of its children to the root directory on Windows of your choice.

### Directory Setup

* /INDIface
  * /bin
    * /win64V-bin-v6.16-Alpha1-release
      * contains the IfSearch6executable and all of its needed DLLs
    * /log
      * detailed logs will be written here for each run
    * /plugins/imageformat
      * support files for reading image formats beyond `.BMP`and `.PNG`, such as `.JPG`.
    * /detectors
      * contains Haar object detector cascades
    * /data
      * contains INDIface resource data file sets (to be used next week)
  * /doc
    * contains this and other documentation
  * /INDIin
    * /console
      * contains a few sample images
  * /INDIout
    * /console
      * /D20210515-T0256-sample
        * contains sample results of processing the console input directory
      * future runs will place output here in a timestamp directory
        * /MarkedFrame
          * contains frame images with detected faces (above MinQuality) marked as well as rejected faces with a dashed border
        * /Face
          * contains the marked cropped face output with eyes marked and the normalized face without any markings.
          * _Note: If less than one each left and right eye no normalized face is possible._



### Path

* You may want to add the bin directory to the system `PATH` environment variable.

## Running
* Open a command prompt
* `cd \Distrib\INDIface\bin\win64V-bin-v6.16-Alpha1-release` if yoou have not added this directory to `PATH`
* Run `IfSearch6`with any desired command line options

### Command Line Options

#### Face Object Grouping

* `/Frame/ObjectDetection/Grouping`
  * `MinQuality=`{PerMille}
    * default: 500&permil; 

#### Object Detection Resources

* `/Resources/ObjectDetection`
  * `BaseDir=` 
    * default: `../detectors`
  * `/FaceFrontalFull`
    * CascadeXmlFile=
      * default: `v4/haarcascade_frontalface_alt.Xml`
  * /EyeEither
    * CascadeXmlFile=
      * default: `v4/haarcascade_eye.Xml`



