         _________________________________
        /                                 \
        |     MicMac Cluster Project      |
        \_________________________________/



# INTRODUCTION:

MicMac is a free open-source (Cecill-B licence) photogrammetric suite that can be used in a variety of 3D
reconstruction scenarios. In aims mainly at professionnal or academic users but constant efforts are made
to make it more accessible to the general public. One of MicMac strengths is its high degree of versatility.
It can indeed be used in various fields : cartography, environment, industry, forestry, heritage, archaeology,...
MicMac allows both the creation of 3D models and of ortho-imagery when appropriate.

But MicMac works really bad with dataset that exceeds a dozen of images. And Especially if the dataset includes
different points of view. The aim of this project is to give a solution about this Micmac weak point, without
trying to seek a alternative into the source code. Because of a source code we didn't understand hardly anything,
but that offers a pretty good 3D reconstruction, the best way to manage with MicMac is to build a wrapper on
MicMac command which clusterize the dataset into logical subset.






# AUTHORS:

    SEAL Research Laboratory (EPITA)  |  Kevin Guillet (cloud441)
                                      |  Tanzim Ahmed Mostafa





# PREREQUISITES:

    --> cmake
    --> boost
    --> micmac (and prerequisites)







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
