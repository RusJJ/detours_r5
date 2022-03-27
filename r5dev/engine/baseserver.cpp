//=============================================================================//
//
// Purpose: 
//
// $NoKeywords: $
//
//=============================================================================//
// baseserver.cpp: implementation of the CBaseServer class.
//
/////////////////////////////////////////////////////////////////////////////////
#include "core/stdafx.h"
#include "common/protocol.h"
#include "engine/baseserver.h"
#include "engine/baseclient.h"
#include "public/include/edict.h"

//---------------------------------------------------------------------------------
// Purpose: Gets the number of human players on the server
// Output : int64_t
// !TODO  : Rebuild properly..
//---------------------------------------------------------------------------------
int CBaseServer::GetNumHumanPlayers(void) const
{
    int nHumans = 0;
    for (int i = 0; i < g_ServerGlobalVariables->m_nMaxClients; i++)
    {
        CBaseClient* client = g_pClient->GetClient(i);
        if (!client)
            continue;

        if (client->IsConnected())
            nHumans++;
    }

    return nHumans;
}

//---------------------------------------------------------------------------------
// Purpose: Gets the number of fake clients on the server
// Output : int64_t
// !TODO  : Rebuild properly..
//---------------------------------------------------------------------------------
int CBaseServer::GetNumFakeClients(void) const
{
    int nBots = 0;
    for (int i = 0; i < g_ServerGlobalVariables->m_nMaxClients; i++)
    {
        CBaseClient* client = g_pClient->GetClient(i);
        if (!client)
            continue;

        if (client->IsConnected() && client->IsFakeClient())
            nBots++;
    }

    return nBots;
}

CBaseServer* g_pServer = new CBaseServer(); // !TODO: Replace with engine global if found.