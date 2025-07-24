#include "../menu.h"
#include <memory>

std::shared_ptr<Menu> make_cs() {
  return std::make_shared<Menu>(
    "Carotid sinus",
    "\n\n The carotid sinus is a baroreceptor. This allows for homeostatic mechanisms to monitor \
blood pressure. The baroreceptors inside the sinus are innervated by the glossopharyngeal \
nerve (CN IX).\n\n\
It is a very sensitive site of the body as stimulation can drive large-scale reflex effects \
throughout the body. Physical assault occuring at this point produces massive baroflex \
activation and can cause cerebral ischemia.\n\n\
The sinus often has artherosclerotic plaques because of disturbed hemodynamics. Because \
of these plaques, which can lead to ischemic strokes and transient ischemic attacks, carotid \
endarterectomies are usually done for preventative healthcare.[1]\n\n\
Sources:\n\
[1]. https://en.wikipedia.org/wiki/Carotid_sinus",
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
cells situated at the bifurcation of each common carotid artery in its tunica externa.[1]\n\n\
The carotid body detects changes in the composition of arterial blood flowing through it, mainly the partial pressure of arterial oxygen, \
but also of carbon dioxide. It is also sensitive to changes in blood pH, and temperature.[2]\n\n\
Sources:\n\
[1]. https://iowaprotocols.medicine.uiowa.edu/protocols/carotid-body-and-carotid-sinus-general-information\n\
[2]. https://en.wikipedia.org/wiki/Carotid_body",
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
Anastomoses\n \
It forms anastomoses with the anterior tympanic branch of the maxillary artery, and the stylomastoid artery.[4]:416\n\n\
Variation\n \
Because the caroticotympanic artery is more often absent than present, \
some controversy exists as to whether these are should be classified as an anatomical variation.[2]\n\n\
Nevertheless, its relevance to internal carotid artery pathologies supports its continued classification as a non-variation anatomical structure.[3]\n\n\
Sources:\n\
[1]. https://en.wikipedia.org/wiki/Caroticotympanic_arteries\n\
[2]. https://karger.com/cto/article-abstract/166/3/319/89248/\n\
[3]. http://pubs.rsna.org/doi/10.1148/131.1.133\n\
[4]. Standring, Susan (2020). Gray's Anatomy: The Anatomical Basis of Clinical Practice (42th ed.). New York. ISBN 978-0-7020-7707-4. OCLC 1201341621.",
    "Osseous part of the pharyngotympanic (Eustachian) tube.[4]:706",
    "None",
    "Petrous part of the internal carotid artery",
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
    "\n\nThe artery of the pterygoid canal (or Vidian artery) is an artery in the pterygoid canal.\n\n\
It usually arises from the external carotid artery,[1] but can arise from either the internal or external \
carotid artery or serve as an anastomosis between the two.[2] Sometimes it originates as a branch \
of the distal maxillary artery.[3] When this artery arises from the internal carotid artery, \
it arises from C2 (petrous segment) of the internal carotid.[4]\n\n\
The eponym, Vidian artery is named after Italian surgeon and anatomist Vidius Vidius.\n\n\
Supply\n \
This artery supplies the Eustachian tube, tympanic cavity and the superior portion of the pharynx.[3]\n\n\
Sources:\n\
[1]. http://www.medscape.com/viewarticle/494394_2\n\
[2]. https://en.wikipedia.org/wiki/Artery_of_the_pterygoid_canal\n\
[3]. https://radiopaedia.org/articles/vidian-artery-2\n\
[4]. https://en.wikipedia.org/wiki/Internal_carotid_artery",
    std::vector<std::string>{
      "External carotid artery",
      "Internal carotid artery"
    }
  );
}

std::shared_ptr<Menu> make_ihpa() {
  return std::make_shared<Menu>(
    "Inferior hypophyseal artery",
    "\n\nThe inferior hypophyseal artery is an artery in the head. It is a branch of the cavernous carotid artery, \
itself from the internal carotid artery.[1] It supplies the posterior pituitary of the pituitary gland.[2]\n\n\
Alternatively, it may arise from the meningohypophyseal artery, and may also give off the medial clival artery.[3]\n\n\
Sources:\n\
[1]. Marieb, Elaine (2014). Anatomy & physiology. Glenview, IL: Pearson Education, Inc. ISBN 978-0321861580.\n\
[2]. Maynard, Robert Lewis; Downes, Noel (2019). \"16 - Endocrine Glands\". Anatomy and Histology of the Laboratory Rat in Toxicology and Biomedical Research. Academic Press. pp. 185–196. doi:10.1016/B978-0-12-811837-5.00016-2. ISBN 978-0-12-811837-5. S2CID 239275973.\n\
[3]. Seker, Askin; Martins, Carolina; Rhoton Jr., Albert L. (2010). \"2 - Meningeal Anatomy\". Meningiomas. Saunders. pp. 11–51. doi:10.1016/B978-1-4160-5654-6.00002-7. ISBN 978-1-4160-5654-6.",

    std::vector<std::string>{
      "Meningohypophyseal artery",
      "Internal carotid artery",
      "Medial clival artery"
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
      "Artery of the pterygoid canal (Vidian artery)",
      "Inferior hypophyseal artery"
    },

    std::vector<std::function<void()>>{
      []{ make_cs()->run(); },
      []{ make_cb()->run(); },
      []{ make_ctna()->run(); },
      []{ make_vda()->run(); },
      []{ make_ihpa()->run(); }
    },

    "test",
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