///////////////////////////////////////////////////////////////////////////////
// Name:        src/common/headercolcmn.cpp
// Purpose:     wxHeaderColumnBase implementation
// Author:      Vadim Zeitlin
// Created:     2008-12-02
// RCS-ID:      $Id$
// Copyright:   (c) 2008 Vadim Zeitlin <vadim@wxwidgets.org>
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

// ============================================================================
// declarations
// ============================================================================

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

// for compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
#endif // WX_PRECOMP

#include "wx/headercol.h"

// ============================================================================
// wxHeaderColumnBase implementation
// ============================================================================

void wxHeaderColumnBase::SetIndividualFlags(int flags)
{
    SetResizeable((flags & wxCOL_RESIZABLE) != 0);
    SetSortable((flags & wxCOL_SORTABLE) != 0);
    SetReorderable((flags & wxCOL_REORDERABLE) != 0);
    SetHidden((flags & wxCOL_HIDDEN) != 0);
}

int wxHeaderColumnBase::GetFromIndividualFlags() const
{
    int flags = 0;

    if ( IsResizeable() )
        flags |= wxCOL_RESIZABLE;
    if ( IsSortable() )
        flags |= wxCOL_SORTABLE;
    if ( IsReorderable() )
        flags |= wxCOL_REORDERABLE;
    if ( IsHidden() )
        flags |= wxCOL_HIDDEN;

    return flags;
}

void wxHeaderColumnBase::ChangeFlag(int flag, bool set)
{
    if ( HasFlag(flag) != set )
        ToggleFlag(flag);
}

void wxHeaderColumnBase::SetFlag(int flag)
{
    int flags = GetFlags();
    if ( !(flags & flag) )
        SetFlags(flags | flag);
}

void wxHeaderColumnBase::ClearFlag(int flag)
{
    int flags = GetFlags();
    if ( flags & flag )
        SetFlags(flags & ~flag);
}

void wxHeaderColumnBase::ToggleFlag(int flag)
{
    int flags = GetFlags();
    if ( flags & flag )
        flags &= ~flag;
    else
        flags |= flag;

    SetFlags(flags);
}


