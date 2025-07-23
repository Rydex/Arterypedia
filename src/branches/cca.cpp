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

std::shared_ptr<Menu> make_ic() {
  return std::make_shared<Menu>(
    "Internal carotid artery",
    std::vector<std::string>{
      "Carotid sinus",
      "Carotid body"
    },

    std::vector<std::function<void()>>{
      []{ make_cs()->run(); },
      []{ make_cb()->run(); }
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