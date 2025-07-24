#include "../menu.h"
#include <memory>

std::shared_ptr<Menu> make_cs() {
  return std::make_shared<Menu>(
    "Carotid sinus",
    "\n\n The carotid sinus is a baroreceptor. This allows for homeostatic mechanisms to monitor \
blood pressure. The baroreceptors inside the sinus are innervated by the glossopharyngeal \
nerve (CN IX).\n\n \
It is a very sensitive site of the body as stimulation can drive large-scale reflex effects \
throughout the body. Physical assault occuring at this point produces massive baroflex \
activation and can cause cerebral ischemia.\n\n \
The sinus often has artherosclerotic plaques because of disturbed hemodynamics. Because \
of these plaques, which can lead to ischemic strokes and transient ischemic attacks, carotid \
endarterectomies are usually done for preventative healthcare.[1]\n\n\
Sources:\n\
[1]. https://en.wikipedia.org/wiki/Carotid_sinus\n",
    std::vector<std::string>{
      "Carotid body",
      "Internal carotid artery"
    }
  );
}

std::shared_ptr<Menu> make_cb() {
  return std::make_shared<Menu>(
    "Carotid body",
    "\n\n The carotid body is a small cluster of peripheral chemoreceptor cells and supporting sustentacular \
cells situated at the bifurcation of each common carotid artery in its tunica externa.[1]\n\n \
The carotid body detects changes in the composition of arterial blood flowing through it, mainly the partial pressure of arterial oxygen, \
but also of carbon dioxide. It is also sensitive to changes in blood pH, and temperature.[2]\n\n\
Sources:\n\
[1]. https://iowaprotocols.medicine.uiowa.edu/protocols/carotid-body-and-carotid-sinus-general-information\n\
[2]. https://en.wikipedia.org/wiki/Carotid_body\n",
    std::vector<std::string>{
      "Carotid sinus",
      "Internal carotid artery"
    }
  );
}

std::shared_ptr<Menu> make_ctna() {
  return std::make_shared<Menu>(
    "Caroticotympanic arteries",
    "\n\n The caroticotympanic artery (tympanic branch) is a small, \
sometimes doubled artery which arises from the petrous part of the internal carotid artery.[1]\n\n\
Supplies\n \
Contributes arterial supply to the osseous part of the pharyngotympanic (Eustachian) tube.[4]:706\n\n\
Anastomoses\n \
It forms anastomoses with the anterior tympanic branch of the maxillary artery, and the stylomastoid artery.[4]:416\n\n\
Variation\n \
Because the caroticotympanic artery is more often absent than present, \
some controversy exists as to whether these are should be classified as an anatomical variation.[2]\n\n \
Nevertheless, its relevance to internal carotid artery pathologies supports its continued classification as a non-variation anatomical structure.[3]\n\n\
Sources:\n\
[1]. https://en.wikipedia.org/wiki/Caroticotympanic_arteries\n\
[2]. https://karger.com/cto/article-abstract/166/3/319/89248/\n\
[3]. http://pubs.rsna.org/doi/10.1148/131.1.133\n\
[4]. Standring, Susan (2020). Gray's Anatomy: The Anatomical Basis of Clinical Practice (42th ed.). New York. ISBN 978-0-7020-7707-4. OCLC 1201341621.",
    std::vector<std::string>{
      "Internal carotid artery",
      "Maxillary artery",
      "Stylomastoid artery"
    }
  );
}

std::shared_ptr<Menu> make_vda() {
  return std::make_shared<Menu>(
    "Vidian artery (artery of the pterygoid canal)",
    "\n\nThe artery of the pterygoid canal (or Vidian artery) is an artery in the pterygoid canal.\n\n \
It usually arises from the external carotid artery,[1] but can arise from either the internal or external \
carotid artery or serve as an anastomosis between the two.[2] Sometimes it originates as a branch \
of the distal maxillary artery.[3]\n\n\
The eponym, Vidian artery is named after Italian surgeon and anatomist Vidius Vidius.\n\n\
Supplies: Eustachian tube, tympanic cavity and the superior portion of the pharynx.[3]\n\n\
Sources:\n\
[1]. http://www.medscape.com/viewarticle/494394_2\n\
[2]. https://en.wikipedia.org/wiki/Artery_of_the_pterygoid_canal\n\
[3]. https://radiopaedia.org/articles/vidian-artery-2",
    std::vector<std::string>{
      "External carotid artery",
      "Internal carotid artery"
    }
  );
}

std::shared_ptr<Menu> make_ic() {
  return std::make_shared<Menu>(
    "Internal carotid artery",
    std::vector<std::string>{
      "Carotid sinus",
      "Carotid body",
      "Caroticotympanic arteries",
      "Artery of the pterygoid canal (Vidian artery)"
    },

    std::vector<std::function<void()>>{
      []{ make_cs()->run(); },
      []{ make_cb()->run(); },
      []{ make_ctna()->run(); },
      []{ make_vda()->run(); }
    },
    true
  );
}

std::shared_ptr<Menu> make_cca() {
  return std::make_shared<Menu>(
    "Branches of the common carotid",
    std::vector<std::string>{
      "External carotid",
      "Internal carotid"
    },

    std::vector<std::function<void()>>{
      []{ print("hi\n"); },
      []{ make_ic()->run(); }
    },
    true
  );
}