# TruthAnalizer
Project with everything needed to start doing truth analysis at SBND, made for members of the UGR neutrino group by Luis Pelegrina Gutierrez (lpelegri@ugr.es).

The files "CMakeLists.txt", "main.cpp" and the folder "cmake-build-debug" may be ignored, as they are only included for the project to be used along with CLion.

The folder "LArSoft_code" contains the analizer used to generate trees with truth information about BNB neutrino events. The fhicls needed to run the analizer and extract the information from reco2 art-root files are also included. This analizer is meant to only be used with files containing a single neutrino interaction per LArSoft events, using it with a file with multiple interactions per event will not give a correct output. This code was created for sbndcode version v09_82_02_01.

The folder "Data" is where the analized files are meant to be stored in order to be used in the example "read_tree.C". These files can be found inside the sbnd-gvpms nodes in the folder "/exp/sbnd/data/users/lpelegri/Truth_Example/" under the name "analysis_output_truth_BNB_single_100k_events.root" for 100k events and "analysis_output_truth_BNB_single_100_events.root" for 100 events. The code "scp.sh" is meant to be run in the terminal and downloads the Data directly into the folder, please read it and modify it before usage. If you are unable to access these folder ask Luis Pelegrina Gutiérrez (lpelegrina@ugr.es) for the files (Or generate them by asking any person in the group able to run the LArSoft analysis chain).

The file "Includes.h" has all the root dependencies required for the code to run smoothly.

The file "tree_utils.cpp" contains some helper functions to read the trees containing the truth information and the declaration of the variables contained in the truth trees. It also includes an explanation of each variable and information about the structure of the trees created by the analizer module, please refer to it in order to start using the truth trees.

The file "read_tree.C" is a code example to exemplify the use of the information inside the tree. As a starting point is heavely recommended to run it and try to understand how it works before jumping to use the trees for analysis. The code reads the tree contained in the folder "Data" and prints all its information on the terminal.