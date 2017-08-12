#include "cbase.h"
#include "c_mom_online_ghost.h"
#include "mom_player_shared.h"
#include "clientmode.h"

#include "tier0/memdbgon.h"

IMPLEMENT_CLIENTCLASS_DT(C_MomentumOnlineGhostEntity, DT_MOM_OnlineGhost, CMomentumOnlineGhostEntity)
    RecvPropString(RECVINFO(m_pszGhostName)),
END_RECV_TABLE();

C_MomentumOnlineGhostEntity::C_MomentumOnlineGhostEntity(): m_pEntityPanel(nullptr)
{
    m_pszGhostName[0] = '\0';
}

C_MomentumOnlineGhostEntity::~C_MomentumOnlineGhostEntity()
{
    if (m_pEntityPanel)
        m_pEntityPanel->DeletePanel();

    m_pEntityPanel = nullptr;
}

void C_MomentumOnlineGhostEntity::Spawn()
{
    Precache();
    SetNextClientThink(CLIENT_THINK_ALWAYS);

    m_pEntityPanel = new CEntityPanel(g_pClientMode->GetViewport(), "GhostEntityPanel");
    KeyValues* pKv = new KeyValues("blah");
    pKv->SetString("offset", "0 0");
    pKv->SetString("size", "30 30");
    m_pEntityPanel->Init(pKv, this);
    m_pEntityPanel->SetVisible(true);
    m_pEntityPanel->SetFgColor(Color(255, 255, 255, 255));
    pKv->deleteThis();
}
void C_MomentumOnlineGhostEntity::ClientThink()
{
    SetNextClientThink(CLIENT_THINK_ALWAYS);
}