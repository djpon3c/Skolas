#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
/*************************************************************************************************
* Autors: Artis Celitamns
* Grupa: D2-1
* Paskaidrojums : Si spele saucas "karatuves", speletaja merkis ir uzminet pareizo vardu, minot pa burtiem, katrs pareizais burts veido vardu.
* Ar katru nepareizi uzminetu burtu speletajam paliek mazak dzivibas, un kad tas beidzas, speletaju pakar un spele beidzas.
*
* Skaidrojumi recenzetajam :
*
* \t  - horizontala atstarpe
* \n  - jauna linija
* toupper - padara piemeram burtu t par lielo burtu T, jo slepenajs vards rakstits ar lielajiem burtiem.
* MAX_NEPAREIZS - maksimalas iespejas pirms zaudet
* vector<string> - Sitas lauj aizvietot masivu, kura es ievadu manus minejumus, ka ari es varu izmantot push_back
* push_back - push_back palielina masīvu, lai pielāgotu jauno elementu. Vektoram ir  lielums. Lielums ir tas, cik daudz fiziskās atmiņas ir pieejamas,
* pirms nepieciešams atkārtoti piešķirt vietu push_back pieprasījumam. Lielums ir tas, cik daudz elementu pašlaik tiek glabāti.
* npos -  ir statīva  konstantes vērtība ar lielāko iespējamo vērtību elementa tipam
*
**************************************************************************************************/



using namespace std;

int main()
{

    const int MAX_NEPAREIZS = 8;

    vector<string> vards;
    vards.push_back("TEHNIKUMS");
    vards.push_back("MACIBAS");
    vards.push_back("PROGRAMESANA");
    vards.push_back("KLADE");
    vards.push_back("CODEBLOCKS");
    vards.push_back("EKSAMENS");
    vards.push_back("PROJEKTS");
    vards.push_back("NANOMATERIALS");
    vards.push_back("HIDROELEKTROSTACIJA");


    srand(static_cast<unsigned int>(time(0)));  // izveido random numuru no kura velak tiks izmantots slepenaja varda izvele
    random_shuffle(vards.begin(), vards.end());  // izvelas vienu no vardiem kas ir vektora "vards" randoma un ievieto to ka slepeno vardu.
    const string MINEJUMA_VARDS = vards[0];
    int kluda = 0;
    string tikTalu(MINEJUMA_VARDS.size(), '-');   // izvada uz ekrana "---" tik daudz reizes cik burtu ir varda.
    string izmantotais_burts = "";
    cout<<"\n\t\t\t ----------------------\n" << endl;
    cout << "\t\t\t Sveicinati mana spele!" << endl;
	cout<<"\n\t\t\t ----------------------\n\n" << endl;
	cout <<"\n Tev ir " <<(MAX_NEPAREIZS - kluda)<< " minejumi, gl hf! \n" << endl;


    while ((kluda < MAX_NEPAREIZS) && (tikTalu != MINEJUMA_VARDS))
    {
        cout << " Tu jau izmantoji sos burtus:" << izmantotais_burts << endl;
        cout << " Tavs vards izskatas sadi: " << tikTalu << endl;

        char minejums;
        cout << "\n\n Ievadi savu minejumu burtu ";
        cin >> minejums;
        minejums = toupper(minejums);

        while (izmantotais_burts.find(minejums) != string::npos)
        {
            cout << " Tu jau mineji so burtu " << minejums << endl;
            cout << " Ievadi savu minejumu: ";
            cin >> minejums;
            minejums = toupper(minejums);
        }

        izmantotais_burts += minejums;

        if (MINEJUMA_VARDS.find(minejums) != string::npos)    // find - atrod to burtu slepenaja varda to ko ievada lietotajs, starp tiem kur ir pasa elementa diapazona
        {
            cout << " Tas ir pareizi! " << minejums << " ir slepenaja varda." << endl;
            for (unsigned int i = 0; i < MINEJUMA_VARDS.length(); ++i)
			{
                if (MINEJUMA_VARDS[i] == minejums)
				{
                    tikTalu[i] = minejums;
				}
			}
        }
        else
        {
			++kluda;
            cout << " Piedod, " << minejums << "  burta nav minetaja varda " << endl;
			cout << " Tev palika " <<(MAX_NEPAREIZS - kluda)<< " minejuma iespejas ." << endl;

        }
    }
    if (kluda == MAX_NEPAREIZS)
	{
        cout << " Jus zaudejat, jus pakara karatuves!" << endl;

	}
    else
	{
        cout << " Apsveicu! Jus uzminejat slepeno vardu" << endl;
	}

	//Ieliku sito lai butu vairak funkciju ka prasija skolotajs
    cout << " Slepenajs vards bija " << MINEJUMA_VARDS << endl;
	int Vertejums;
	cout << " Novertejiet manu speli: " << endl;
	cout << " 1 - Bija jautri" << endl;
	cout << " 2 - Bija ok" << endl;
	cout << " 3 - Bija drausmigi" << endl;
	cin >> Vertejums;
	switch (Vertejums)
	{
	case 1: cout <<" Liels paldies, paldies par labu vertejumu \n"; break; // es uzzinaju ka \n var iamantot ka endline un vinam ir cita funkcionalitate, piemeram ja es izmantotu endl; break; funkcija saja veida nenostradatu
	case 2: cout <<" Nakosreiz uztaisisu labak, paldies par vertejumu \n"; break;
	case 3: cout <<" Atvainojos par tadu meslu, nakosreiz uztaisisu kaut ko sakarigaku \n"; break;
	default: cout <<" Visu labu \n"; break;
	}
	system("pause");
    return 0;
}
