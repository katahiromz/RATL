/*
 * PROJECT:     ReactOS ATL
 * LICENSE:     LGPL-2.0-or-later (https://spdx.org/licenses/LGPL-2.0-or-later)
 * PURPOSE:     String conversion
 * COPYRIGHT:   Copyright 2023 Katayama Hirofumi MZ <katayama.hirofumi.mz@gmail.com>
 */

#ifndef __ATLCONV_H__
#define __ATLCONV_H__

#pragma once

#include "atlbase.h"

namespace ATL
{

template <int t_nBufferLength = 128>
class CA2CAEX
{
public:
    LPCSTR m_psz;

    CA2CAEX(_In_z_ LPCSTR psz) : m_psz(psz) { }
    CA2CAEX(_In_z_ LPCSTR psz, _In_ UINT nCodePage) : m_psz(psz) { }
    ~CA2CAEX() throw() { }

    _Ret_z_ operator LPCSTR() const throw() { return m_psz; }

private:
    // CA2CAEX is not copyable
    CA2CAEX(_In_ const CA2CAEX&) throw();
    CA2CAEX& operator=(_In_ const CA2CAEX&) throw();
};

template <int t_nBufferLength = 128>
class CW2CWEX
{
public:
    LPCWSTR m_psz;

    CW2CWEX(_In_z_ LPCWSTR psz) : m_psz(psz) { }
    CW2CWEX(_In_z_ LPCWSTR psz, _In_ UINT nCodePage) : m_psz(psz) { }
    ~CW2CWEX() throw() { }

    _Ret_z_ operator LPCWSTR() const throw() { return m_psz; }

private:
    // CW2CWEX is not copyable
    CW2CWEX(_In_ const CW2CWEX&) throw();
    CW2CWEX& operator=(_In_ const CW2CWEX&) throw();
};

template <int t_nBufferLength = 128>
class CA2AEX
{
public:
    LPSTR m_psz;
    char m_szBuffer[t_nBufferLength];

    CA2AEX(_In_z_ LPCSTR psz)
    {
        Init(psz);
    }

    CA2AEX(_In_z_ LPCSTR psz, _In_ UINT nCodePage)
    {
        Init(psz);
    }

    ~CA2AEX() throw()
    {
        if (m_psz != m_szBuffer)
            free(m_psz);
    }

    _Ret_z_ operator LPSTR() const throw()
    {
        return m_psz;
    }

private:
    // CA2AEX is not copyable
    CA2AEX(_In_ const CA2AEX &) throw();
    CA2AEX& operator=(_In_ const CA2AEX &) throw();

    void Init(_In_z_ LPCSTR psz)
    {
        int cchMax = lstrlenA(psz) + 1;
        if (cchMax <= t_nBufferLength)
        {
#ifdef _STRSAFE_H_INCLUDED_
            StringCchCopyA(m_szBuffer, _countof(m_szBuffer), psz);
#else
            lstrcpynA(m_szBuffer, psz, _countof(m_szBuffer));
#endif
            m_psz = m_szBuffer;
            return;
        }

        m_psz = _strdup(psz);
        if (!m_psz)
            AtlThrow(E_OUTOFMEMORY);
    }
};

template <int t_nBufferLength = 128>
class CW2WEX
{
public:
    LPWSTR m_psz;
    wchar_t m_szBuffer[t_nBufferLength];

    CW2WEX(_In_z_ LPCWSTR psz)
    {
        Init(psz);
    }

    CW2WEX(_In_z_ LPCWSTR psz, _In_ UINT nCodePage)
    {
        Init(psz);
    }

    ~CW2WEX() throw()
    {
        if (m_psz != m_szBuffer)
            free(m_psz);
    }

    _Ret_z_ operator LPWSTR() const throw()
    {
        return m_psz;
    }

private:
    // CW2WEX is not copyable
    CW2WEX(_In_ const CW2WEX&) throw();
    CW2WEX& operator=(_In_ const CW2WEX&) throw();

    void Init(_In_z_ LPCWSTR psz)
    {
        int cchMax = lstrlenW(psz);
        if (cchMax <= t_nBufferLength)
        {
#ifdef _STRSAFE_H_INCLUDED_
            StringCchCopyW(m_szBuffer, _countof(m_szBuffer), psz);
#else
            lstrcpynW(m_szBuffer, psz, _countof(m_szBuffer));
#endif
            m_psz = m_szBuffer;
            return;
        }

        m_psz = _wcsdup(psz);
        if (!m_psz)
            AtlThrow(E_OUTOFMEMORY);
    }
};

template <int t_nBufferLength = 128>
class CA2WEX
{
public:
    LPWSTR m_psz;
    wchar_t m_szBuffer[t_nBufferLength];

    CA2WEX(_In_z_ LPCSTR psz)
    {
        Init(psz, CP_ACP);
    }

    CA2WEX(_In_z_ LPCSTR psz, _In_ UINT nCodePage)
    {
        Init(psz, nCodePage);
    }

    ~CA2WEX() throw()
    {
        if (m_psz != m_szBuffer)
            free(m_psz);
    }

    _Ret_z_ operator LPWSTR() const throw()
    {
        return m_psz;
    }

private:
    // CA2WEX is not copyable
    CA2WEX(_In_ const CA2WEX&) throw();
    CA2WEX& operator=(_In_ const CA2WEX&) throw();

    void Init(_In_z_ LPCSTR psz, _In_ UINT nCodePage)
    {
        int cchMax = MultiByteToWideChar(nCodePage, 0, psz, -1, NULL, 0);
        if (cchMax <= t_nBufferLength)
        {
            MultiByteToWideChar(nCodePage, 0, psz, -1, m_szBuffer, _countof(m_szBuffer));
            m_szBuffer[_countof(m_szBuffer) - 1] = 0;
            m_psz = m_szBuffer;
            return;
        }

        m_psz = (LPWSTR)malloc(cchMax * sizeof(WCHAR));
        if (!m_psz)
            AtlThrow(E_OUTOFMEMORY);

        MultiByteToWideChar(nCodePage, 0, psz, -1, m_psz, cchMax);
        m_psz[cchMax - 1] = 0;
    }
};

template <int t_nBufferLength = 128>
class CW2AEX
{
public:
    LPSTR m_psz;
    char m_szBuffer[t_nBufferLength];

    CW2AEX(_In_z_ LPCWSTR psz)
    {
        Init(psz, CP_ACP);
    }

    CW2AEX(_In_z_ LPCWSTR psz, _In_ UINT nCodePage)
    {
        Init(psz, nCodePage);
    }

    ~CW2AEX() throw()
    {
        if (m_psz != m_szBuffer)
            free(m_psz);
    }

    _Ret_z_ operator LPSTR() const throw()
    {
        return m_psz;
    }

private:
    // CW2AEX is not copyable
    CW2AEX(_In_ const CW2AEX&) throw();
    CW2AEX& operator=(_In_ const CW2AEX&) throw();

    void Init(_In_z_ LPCWSTR psz, _In_ UINT nConvertCodePage)
    {
        int cchMax = WideCharToMultiByte(nConvertCodePage, 0, psz, -1, NULL, 0, NULL, NULL);
        if (cchMax <= t_nBufferLength)
        {
            WideCharToMultiByte(nConvertCodePage, 0, psz, -1, m_szBuffer, _countof(m_szBuffer),
                                NULL, NULL);
            m_szBuffer[_countof(m_szBuffer) - 1] = 0;
            m_psz = m_szBuffer;
            return;
        }

        m_psz = (LPSTR)malloc(cchMax * sizeof(CHAR));
        if (!m_psz)
            AtlThrow(E_OUTOFMEMORY);

        WideCharToMultiByte(nConvertCodePage, 0, psz, -1, m_psz, cchMax, NULL, NULL);
        m_psz[cchMax - 1] = 0;
    }
};

typedef CA2AEX<128> CA2A;
typedef CW2AEX<128> CW2A;
typedef CA2WEX<128> CA2W;
typedef CW2WEX<128> CW2W;
typedef CA2CAEX<128> CA2CA;
typedef CW2CWEX<128> CW2CW;

#ifdef UNICODE
    #define CA2CTEX CA2WEX
    #define CA2TEX  CA2WEX
    #define CT2AEX  CW2AEX
    #define CT2CAEX CW2AEX
    #define CT2CWEX CW2CWEX
    #define CT2WEX  CW2WEX
    #define CW2CTEX CW2CWEX
    #define CW2CTEX CW2CWEX
#else
    #define CA2CTEX CA2CAEX
    #define CA2TEX  CA2AEX
    #define CT2AEX  CA2AEX
    #define CT2CAEX CA2CAEX
    #define CT2CWEX CA2WEX
    #define CT2WEX  CA2WEX
    #define CW2CTEX CW2AEX
    #define CW2TEX  CW2AEX
#endif

} // namespace ATL

#endif // ndef __ATLCONV_H__
