#ifndef PAV_PCH_H
#define PAV_PCH_H

// Project precompile header
// If you are going to edit this I assume you have a
// solid understanding of msvc's precompile header(pch) system
// If not please avoid touching/changing this file, thank you

// STL
#include <array>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#include <memory>
#include <functional>
#include <cstdio>

#include <string>

#include <mutex>
#include <thread>

// 3rd Party
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>

// PAV
#include "pav_pcs.h"

#include "core/eea/pav_assert.h"

#include "core/util/signal.h"

#endif // PAV_PCH_H
