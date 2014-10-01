#ifndef KITTI_GLOBAL_H
#define KITTI_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef KITTI_LIB
# define KITTI_EXPORT Q_DECL_EXPORT
#else
# define KITTI_EXPORT Q_DECL_IMPORT
#endif

#endif // KITTI_GLOBAL_H
