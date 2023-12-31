#ifndef DEF_ELEVE
#define DEF_ELEVE

#include "../dict_dyn/dict_dyn.h"
// inclure les groupes
#include "groupes.h"

class Eleve
{
public:
    Eleve();
    Eleve(unsigned int id,
          std::string prenom,
          std::string nom,
          std::string niveau_scolaire,
          Groupes groupes);
    //Eleve(std::string prenom, std::string nom, std::string niveau_scolaire);
    Eleve(const Eleve& eleve);
    ~Eleve();

    unsigned int GetId() const;
    std::string GetPrenom() const;
    std::string GetNom() const;
    std::string GetNiveauScolaire() const;
    unsigned int GetNbMatiere() const;
    unsigned int GetNbMatiereMax() const;

    void SetEleve(unsigned int id, std::string prenom, std::string nom, std::string niveau_scolaire);
    void SetId(unsigned int id);
    void SetPrenom(std::string prenom);
    void SetNom(std::string nom);
    void SetNiveauScolaire(std::string niveau_scolaire);

    void CopyMatiere(TabDynString tab_dyn_ref);
    void SetSecurity(bool security);
    void AddMatiere(std::string value);
    void AddMatiere(std::string value, bool add_with_addition);
    std::string GetMatiere(unsigned int i) const;
    std::string* GetMatieres() const;
    void SetMatiere(unsigned int i, std::string value);
    std::string PopMatiere();
    std::string PopMatiere(int index);
    void RemoveMatiere(std::string value, int num);
    void RemoveMatiere(std::string value);
    void RemoveMatiere(std::string value, bool is_first);



private:
    unsigned int m_id;
    unsigned int m_nb_matiere;
    unsigned int horaire1;
    unsigned int horaire2;
    std::string m_prenom;
    std::string m_nom;
    std::string m_niveau_scolaire;
    TabDynString m_matieres;
    TabDynInt m_horaires;
    Groupes m_groupes;

};

/* SPLIT */

class TabDynEleve : public TabDyn
{
public :
    TabDynEleve();
    TabDynEleve(unsigned int nb_elem_max);
    TabDynEleve(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    TabDynEleve(const TabDynEleve& tab_dyn_ref);
    ~TabDynEleve();

    void Copy(TabDynEleve& tab_dyn_ref);
    void Add(Eleve value);
    void Add(Eleve value, bool add_with_multiple);
    Eleve Get(unsigned int index) const;
    Eleve* GetTab() const;
    void Set(unsigned int index, Eleve value);

    Eleve Pop();
    Eleve Pop(int index);
    void Remove(Eleve value, int num);
    void Remove(Eleve value);
    void Remove(Eleve value, bool is_first);

private :
    Eleve* m_tab;
};

/* SPLIT */

class DictDynIntUnsignedEleve : public DictDyn
{
public:
    DictDynIntUnsignedEleve();
    DictDynIntUnsignedEleve(unsigned int nb_elem_max);
    DictDynIntUnsignedEleve(unsigned int nb_elem_max, bool add_with_multiple, unsigned int number_addition);
    DictDynIntUnsignedEleve(const DictDynIntUnsignedEleve& dict_dyn_ref);
    ~DictDynIntUnsignedEleve();

    void SetParam(bool add_with_multiple, unsigned int number_addition);
    void SetSecurity(bool security);

    void Copy(DictDynIntUnsignedEleve& dict_dyn_ref);
    void Add(int unsigned key, Eleve value);
    void Add(int unsigned key, Eleve value, bool add_with_multiple);
    Eleve Get(int unsigned key) const;
    TabDynIntUnsigned GetTabKeys() const;
    TabDynEleve GetTabValues() const;
    void Set(int unsigned key, Eleve value);

    Eleve Pop(int unsigned key);
    void Remove(Eleve value, int num);
    void Remove(Eleve value);
    void Remove(Eleve value, bool is_first);

protected:
    TabDynIntUnsigned m_tab_keys;
    TabDynEleve m_tab_values;
};

/* SPLIT */

#endif