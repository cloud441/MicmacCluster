         _________________________________
        /                                 \
        |     MicMac Cluster Project      |
        \_________________________________/



# INTRODUCTION:

    MicMac is an open source project that aims at being cross platform. Very few dependencies are mandatory
to have the core program work.
But MicMac works really bad with dataset that exceeds a dozen of images. And Especially if the dataset includes
diferent points of view. The aim of this projetc is to give a solution about this Micmac weak point, without
trying to seek a alternative into the source code. Because of a source code we didn't understand hardly anything,
but that offers a pretty good 3D reconstruction, the best way to manage with MicMac is to build a wrapper on
MicMac command which clusterize the dataset into logical subset.






# PREREQUISITES:

    --> cmake
    --> boost
    --> micmac (and prerequisites)




# AUTHORS:

    SEAL Research Laboratory (EPITA)  |  Kevin Guillet (cloud441)
                                      |  Tanzim Ahmed Mostafa





# TUTORIAL:

To perfectly use this project to clusterize your dataset, please do following steps:

    --> create a build/ directory at the root of the project:
            $ mkdir build

    --> go into the build directory:
            $ cd build/

    --> run the cmake configuration:
            $ cmake ..

    --> compile the project:
            $ make

    --> put your dataset into the data/ directory (all the .JPG images)

    --> take a look at the available option of the clusterizer:
            $ ./clusterizer -h

    --> run the clusterizer (with your options if necessary):
            $ ./clusterizer

    --> Enjoy all the separated cloud created, clouds are into the outputCloud/ directory.
