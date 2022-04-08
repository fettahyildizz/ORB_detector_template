# ORB_detector_template
This repo contains code for basic ORB Feature Detector code template.


## cmake practices

//.local'e yüklenmiş custom libraryinin görülmesi için gerekli. (opencv custom version yüklü ise ve bu versiyonu linklemek istiyorsak kullanılabilir.)
list(APPEND CMAKE_PREFIX_PATH $ENV{HOME}/.local)

