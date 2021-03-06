/*++
Copyright (c) 2011 Microsoft Corporation

Module Name:

    cooperate.h

Abstract:

    Cooperation support

Author:

    Leonardo (leonardo) 2011-05-17

Notes:

--*/
#pragma once

#ifndef SINGLE_THREAD

class cooperation_ctx {
    static bool g_cooperate;
public:
    static bool enabled() { return g_cooperate; }
    static void checkpoint(char const * task);
};

inline void cooperate(char const * task) {
    if (cooperation_ctx::enabled()) cooperation_ctx::checkpoint(task);
}

#else
inline void cooperate(char const *) {}
#endif
