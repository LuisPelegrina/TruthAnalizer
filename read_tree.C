#include "tree_utils.cpp"
#include "Includes.h"

void read_tree()
{
    TTree *tree;
    TFile *input;
    TDirectoryFile *dir;

    TTree *subrun_tree;

    //Declare the variables
    
    string strRuta = "/Users/luispelegrinagutierrez/Desktop/Doctorado/Truth_test/Data/ana_output_single_interaction_BNB.root";
    input = new TFile(strRuta.c_str());
    dir = (TDirectoryFile*)input->Get("ana");
   
    tree =(TTree*)dir->Get("tree");
    subrun_tree =(TTree*)dir->Get("subrun_tree");

    set_branch(tree);
    set_branch_subtree(subrun_tree);

    double total_pot = 0;
    int num_subrun_entries = subrun_tree->GetEntries();

    cout << "Total number of runs: " << num_subrun_entries << endl;
    for(int i_e = 0; i_e < num_subrun_entries; i_e++) {
        subrun_tree->GetEntry(i_e);
        total_pot += POT;
        cout << i_e << " " << POT << endl;
    }
    cout << "Total POT: " << total_pot << endl;

    int num_entries = tree->GetEntries();
    cout << "Total number of events: " << num_entries << endl;
    for(int i_e = 0; i_e < num_entries; i_e++) {
        tree->GetEntry(i_e);
        cout << "---- event " << event_ID << " ----" << endl;

        cout << "Neutrino properties: " << endl;
        cout << "PDG: " << nu_PDG << " Energy: " << nu_E0 << " weight: " << nu_weight << endl;
        cout << "Interaction mode: " << nu_interaction_mode << " Interaction type: " <<  nu_interaction_type << " CCorNC: " << nu_CC_NC << endl;
        cout << "Target: " << nu_target << " HitNuc: " << nu_HitNuc << " HitQuark: "<< nu_HitQuark << endl;
        cout << "W: " <<  nu_W << " X: " << nu_X << " Y: "<< nu_Y << " Qsqr: "<< nu_QSqr << endl;
        cout << endl;

        cout << "Generator Particles: " << endl;
        int num_gen_particles = gen_part_E0->size();
        for(int i_p = 0; i_p < num_gen_particles; i_p++) {
            cout << "ID: " << gen_part_trackID->at(i_p) << " Status code: "<< gen_part_statusCode->at(i_p) <<  " Mother: " << gen_part_mother->at(i_p) << endl;
            cout << "   PDGCode: " << gen_part_PDGcode->at(i_p) << " Mass: " << gen_part_mass->at(i_p) << " Energy: " << gen_part_E0->at(i_p)<< endl;
            cout << "   Start Pos (x,y,z) : (" << gen_part_start_pos_X->at(i_p) << ", " << gen_part_start_pos_Y->at(i_p) << ", " << gen_part_start_pos_Z->at(i_p)  << ")" << endl;
            cout << "   Start Momentum (x,y,z) : (" << gen_part_P0_X->at(i_p) << ", " << gen_part_P0_Y->at(i_p) << ", " << gen_part_P0_Z->at(i_p)  << ")" << endl;
        }
        cout << endl;

        cout << "G4 Particles: " << endl;

        int num_g4_particles = g4_part_E0->size();

        for(int i_p = 0; i_p < num_g4_particles; i_p++) {
            cout << "ID: " << g4_part_trackID->at(i_p) << " Mother: " << g4_part_mother->at(i_p) << endl;
            cout << "   PDGCode: " << g4_part_PDGcode->at(i_p) << " Mass: " << g4_part_mass->at(i_p) << " Initial Energy: " << g4_part_E0->at(i_p) << " Final Energy: " << g4_part_Ef->at(i_p) << endl;
            cout << "   Start Pos (x,y,z) : (" << g4_part_start_pos_X->at(i_p) << ", " << g4_part_start_pos_Y->at(i_p) << ", " << g4_part_start_pos_Z->at(i_p)  << ")" << endl;
            cout << "   End Pos (x,y,z) : (" << g4_part_end_pos_X->at(i_p) << ", " << g4_part_end_pos_Y->at(i_p) << ", " << g4_part_end_pos_Z->at(i_p)  << ")" << endl;
            cout << "   Start Momentum (x,y,z) : (" << g4_part_P0_X->at(i_p) << ", " << g4_part_P0_Y->at(i_p) << ", " << g4_part_P0_Z->at(i_p)  << ")" << endl;
            cout << "   End Momentum (x,y,z) : (" << g4_part_Pf_X->at(i_p) << ", " << g4_part_Pf_Y->at(i_p) << ", " << g4_part_Pf_Z->at(i_p)  << ")" << endl;
            cout << "   Process: " << g4_part_process->at(i_p) << endl;
            cout << "   End_process: " << g4_part_end_process->at(i_p) << endl;
        }
        cout << endl;
        cout << endl << endl;
    }
}