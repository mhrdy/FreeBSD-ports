# $FreeBSD$

PORTNAME=	sysctl
PORTVERSION=	1.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	${LUA_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small sysctl(3) interface for lua

LICENSE=	BSD2CLAUSE

BROKEN_FreeBSD_10=	does not build (error: use of undeclared identifier 'CTLTYPE_S8')

USE_GITHUB=	yes
GH_ACCOUNT=	kAworu
GH_PROJECT=	lua-${PORTNAME}

USES=		pkgconfig lua
PLIST_FILES=	%%LUA_MODSHAREDIR%%/sysctl.lua \
		%%LUA_MODLIBDIR%%/sysctl/core.so

post-patch:
	@${REINPLACE_CMD} -e "s/5.1/${LUA_VER}/g" ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${LUA_MODLIBDIR}/sysctl ${STAGEDIR}${LUA_MODSHAREDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sysctl.lua ${STAGEDIR}${LUA_MODSHAREDIR}/sysctl.lua
	${INSTALL_LIB} ${WRKSRC}/build/core.so ${STAGEDIR}${LUA_MODLIBDIR}/sysctl/core.so

.include <bsd.port.mk>
