DESCRIPTION = "Simple helloworld application"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://myhello.c"

S = "${WORKDIR}"

DEPENDS = "mystatic"
#PROVIDES += "myphy"
do_compile() {
    ${CC} myhello.c ${LDFLAGS} -o hello -lphy
}


do_install() {
    install -d ${D}${bindir}
    install -m 0755 hello ${D}${bindir}
    install -d ${D}${docdir}
}
