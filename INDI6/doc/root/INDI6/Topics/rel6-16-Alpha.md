# rel6-16-Alpha Notes

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
    * 

  * /data

    * contains INDIface resource data file sets (to be used later)

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
        * /NoFaceFrame
          * contains unmarked frames where no qualified faces were detected

        * /MarkedFace
          * contains the marked cropped face output with eyes marked.
          * <del>/NormalFace</del> Future
          
          * normalized face without any markings.
          * _Note: If less than one each left and right eye no normalized face is possible._

### Path

* You may want to add the bin directory to the system `PATH` environment variable.

## Running

* Open a command prompt
* `cd` \{Distrib}`\INDIface\bin\win64V-bin-v6.16-Alpha1-release` if you have not added this directory to `PATH`
* Run `IfSearch6`with any desired command line options

### Command Line Options

#### Input

* [x] `/Input/Dir`={path to input files}



#### Face Object Detection

* `/Frame/ObjectDetection/Finding`
  * [ ] MinAcross
  * [ ] MaxAcross
  * _see also Object Finding option group below_
  * **Note: For Initial Evaluation purposes, these will be fixed at 1 to 10,**

* `/Frame/ObjectDetection/Grouping`
  * _see Object Grouping option group below_

#### Face Feature Object Detection

* `/Face/ObjectDetection/Finding`
  * [ ] TBD: MinAcross
  * [ ] TBD: MaxAcross
  * _see also Object Finding option group below_

* `/Face/ObjectDetection/Grouping`
  * _see Object Grouping option group below_

#### Object Detection Resources

* `/Resources/ObjectDetection/`
  * `BaseDir=` 
    * default: `../detectors`
  * `/FaceFrontalFull`
    * CascadeXmlFile=
      * default: `v4/haarcascade_frontalface_alt.Xml`
  * /EyeEither
    * CascadeXmlFile=
      * default: `v4/haarcascade_eye.Xml`

#### INDIface6 Resources

* `/Resources/INDIface6/`
  * BaseDir=
    * Relative to executable directory
    * default: `../data`
  * MasterFile
    * default: `./Face1/Face1.XML`
  * MaxLayerLoad
    * default: 320

### Option Groups

#### Object Finding

##### Advanced

These options are used to override calculated or system values:

  * [ ] `Factor`
  * [ ] `Neighbors`
  * [ ] `Flags`
  * [ ] `MinWidth` - raw: overrides MaxAcross
  * [ ] `MaxWidth` - raw: overrides MinAcross
  * [ ] `MaxDetectors` - adjusts Factor in conjunction with MinWidth and MaxWidth
* all: Default = -1 use calculated or system values

#### Object Grouping

  * [x] `MinQuality=`{PerMille}
    * default: 500&permil;
    * **For Initial Evaluation, only values from 500 to 998 will be supported.**
  * [x] `MinWidth`={pixels}
    * default: 48 
    * zero disables
  * [ ] `MaxDistance`=TBD
    * default: TBD

#### Output Directories

* [ ] `/Output/`
  * [ ] `Enable`={empty} 
    - list of output directory names to fill
  * [ ] `BaseDir`={none, therefore executable directory}
  - Directories
    * [x] `MarkedFrame/`
    * [x] `NoFaceFrame/`
    * [x] `MarkedFace/`
    * [ ] Future: `NormalFace/`</del
  - Each Directory
    - [ ] `Dir`={DirectoryName}
    - [ ] `Embed`={false}
    - [ ] `FileFormat`={PNG}
    - [ ] `FileQuality`={-1, let writer decide}
    - [ ] Others TBD







