const url = 'https://chat.openai.com/backend-api/conversation';

const headers = {
    'authority': 'chat.openai.com',
    'accept': 'text/event-stream',
    'accept-language': 'en-US',
    'authorization': 'Bearer eyJhbGciOiJSUzI1NiIsInR5cCI6IkpXVCIsImtpZCI6Ik1UaEVOVUpHTkVNMVFURTRNMEZCTWpkQ05UZzVNRFUxUlRVd1FVSkRNRU13UmtGRVFrRXpSZyJ9.eyJodHRwczovL2FwaS5vcGVuYWkuY29tL3Byb2ZpbGUiOnsiZW1haWwiOiJtaXNocmFzaGFzaHdhdC5zaGFyYXRAZ21haWwuY29tIiwiZW1haWxfdmVyaWZpZWQiOnRydWV9LCJodHRwczovL2FwaS5vcGVuYWkuY29tL2F1dGgiOnsicG9pZCI6Im9yZy1EV0xwSk94eWJHRFhONTlSR1oyTDAxYzYiLCJ1c2VyX2lkIjoidXNlci0xOVZ5emhHWmg3SGhhZ1p3NkdQZERoUmkifSwiaXNzIjoiaHR0cHM6Ly9hdXRoMC5vcGVuYWkuY29tLyIsInN1YiI6Imdvb2dsZS1vYXV0aDJ8MTA5MzU0OTE0OTMyMTY3NzkyMTgzIiwiYXVkIjpbImh0dHBzOi8vYXBpLm9wZW5haS5jb20vdjEiLCJodHRwczovL29wZW5haS5vcGVuYWkuYXV0aDBhcHAuY29tL3VzZXJpbmZvIl0sImlhdCI6MTcwMTMzMTQyMywiZXhwIjoxNzAyMTk1NDIzLCJhenAiOiJUZEpJY2JlMTZXb1RIdE45NW55eXdoNUU0eU9vNkl0RyIsInNjb3BlIjoib3BlbmlkIHByb2ZpbGUgZW1haWwgbW9kZWwucmVhZCBtb2RlbC5yZXF1ZXN0IG9yZ2FuaXphdGlvbi5yZWFkIG9yZ2FuaXphdGlvbi53cml0ZSBvZmZsaW5lX2FjY2VzcyJ9.2FfA4tjSjAzHDMKfBBnqePy_IF83prTC_qfMnq1knZlvGnl8tuRi_pm-V6EsITmZiqP9z2UymysPBoIY1ZExEoBabaCKqPdKYTddX5STcAdjzmjY5l6QIlRkOafBgSqHFdmVRC_wIJvAZAdquVHyZdwQxfF7Cr-InD1hjm3j19yh0uYsifARxSrNjhg6iW8UPPDq6Yfecy_hsqCPc1wylFc1h0D0zr-Xv-IsmiSd5Ii0K5WqJtsccPyugTCbzxhoiGRi7ourUxRZXgDRiqVpZwTLNWQ1gckVrsE2V42b7xfsGnBWOYxWtQKIL4FR9mGPaP12nTrMP6Eezh0bzTr09A',
    'content-type': 'application/json',
    'cookie': '__Host-next-auth.csrf-token=1d610200ca1828c2610325c72822a21eab6b9af427f982faee259e8e46c12743%7C0863c9d35a8693ee4c37772a9077f0af10cc9822c13ddd0c06746cf130aac318; intercom-device-id-dgkjq2bp=7bc81a70-c5eb-4ed9-b1ef-c2320bbf465f; _cfuvid=GIHfVEVJ6nA4ELR94rxd.y6BhL7tg7XiJa5HZDjN4sQ-1701331351954-0-604800000; ajs_user_id=user-19VyzhGZh7HhagZw6GPdDhRi; ajs_anonymous_id=10adadba-544e-4796-81d0-a95ce44f7ad9; cf_clearance=.CQCc4jFDWm.NeWy721zWHqEBK8saLAOGF8EUdoYbYA-1701441106-0-1-d4791cee.338d0864.8378430e-0.2.1701441106; __Secure-next-auth.callback-url=https%3A%2F%2Fchat.openai.com; __Secure-next-auth.session-token=eyJhbGciOiJkaXIiLCJlbmMiOiJBMjU2R0NNIn0..rlTnhitBxl4umQI5.b3VwzrCAGHg2o67u4jULTe201BNLuosaW1P43uZ7bQTBBMtkgqs5tQGE4XblJVOA5_CApmDPDPHf1a-mnjbVyCK6BXm8kiwvK7EJnwjuMH8nM9kyA5WjtvUG3S-dCNzcTMc8pq0C7HDgyGVKDRxes76rDulWHasfTBLQVpZ9kPZwdSXjHkzLwjTUD3Id7g_eDNhqYdW-C9B8c5qWkmderfZN97AQ6CdvvnsSKnJji2wt8mNOyOhLIjqMY2Olv1jE6Sz75X6jackmBkEreQIeH_Sy0pZqMZDSa8_FHWpT2AmaUTA2G8K8s5dfjLQ-t9KDV9UsFAKCGUsiuAyid_KnX3tN-2X3VM8xzEIGnX0jzCFY1iC0JlQMWgLlDbpSgXWGVMX3HrGMvnv6ygA3Aaq24c3P8Cn2rUwcn-OBttjlAoq_YYfnvJcRSFAwggsdXRJyhZv8LS4R2wC7oU9FdRYrJXNUIqiV3m3d3obfpRaQ-zsU4XUs4fl6SU-PKl5bvidx0imVs5Qd8IzG5jMgdiuXo_XNdH44oRBAKOVS_rAMUqmD13iXeYfmBiB-aQQnsfe9dzw1PApDEBGhJRycuKE9txh90LnC2QAiL9xanBMrVRxg7y1AC1W24JfX9i2uI4dtReh_-NjOm1Pu0a2gZrAvu3CvduXZf0N8E1Sln-RvpJ1tRnGgRf5iCMYOWQFXMlY-dXcdfpqI1Wd3XMl9tQsbv4WvXt2kvtdidBn6rK6ic8t7fAF7kyKhzBicffItGPtIebWPvMFDoHwtUuaN9B8kvPzBe0JdF_pPt7GCn1KpVdMp5J3lcdPRQUx3RNH84NkXe3xdfKKO57yv-6nhig0XV79ENjgFqCc2yN9paG-i86ltPawEx-KPb1Or1faeoOXWTAVflywz41CxDdO1NJOwiaWcV8K6ev9fHdtMoe2SYsebUEXiXaRzJy38VBHEvu1PwVO2Ij1ZiyHYB9_-SxTnHQ7d25Mkbame_FiASbn4Of82FLAsSlUAqtFiVGOAqYhmsVLCIN30r4IAY18OxqM42UzbdQIfECaXQY7vwa7O8uvoU_biEGoAn5VgZHeIVwSkYDWIlNmZ_bbf7p1ezetWdjkN5yMvyIA01byX_93oV-wgzU-lMr1xdpY8jCL7Peh_yYHX8P4ldklc8evvekn7YV9rYINHjmVQKJYDUAk5ZgpJR-79gWnFmiOfyL343cOlNLnyfMk7vJXZlA_eIeClp9If2uCwidBvIdgEyki8WWyH5qm_2GwXIewEEPk-Dd2PQAoM7jfoqmK3ko9o8eF2ji6KbGhaoSC71ZAzSoI8Lpe7lE2ymfhBtwgKUE0Xt1qUygFZJUHp8paLkBsUoqFSKM--awnyxWWts1Z5KFZ7knfSfXxEQhn8yz_JJ6VsAxksJS9Gpakh7mG_f_dF3GBQM1BoqcO0F16ZdYwsx-gtgVDXXNHoO-sVX8Qm1qTMGJiaFCi-TkwgZtNLVHFz66rpJ4NYB3tjeBxXG6Duf9XxqOl81VjT4gQKdqnb9JYyP6U1liIX8GYNS-vUSWsSgaqQdnoC52aahbiACujtap7c_bHVUlhvUXQTE8Z-lfnt82BrietZaY-7HaJw8RR6pghzhmWz1OrY_ZsK4_WKNRfF5SVs_U7IdIA5JmSpnmJShZNmr4Ey7fwzbR4n2GGWyytv-5MxOdAlTcp9WPsGhg6XgcVXwOjII3JaagLCP2EXZCqb8E_oXgsF3Z2eqJKglc7FpBlBsAPe0-cEltytCwkvldqKO-Dr4mWjrc2vLgqZqTxUVOayJB6pzmglr8AowAvh3AErIgv9xf7v_5jNFB76NH9ahBNYGo-eJd4dqx_l10uFYx-RYSfroGX00T3KRrN5xnwvFZCrJS2zOnkOR8IXz0-LqTjI5rZRzzSWlzZ5Qeu3jHpgiu3-vzZXucKzWO1Qo33pTvTdlgjQ5pFtFKklmWFnmS3nvekmhb8GH5W4Dx-NjjtblyKL-OVaESmqSJhW_jVxKGN_QHkVeu9bWgn8GH5XP6-d8tsvWbwevWL-SdDQ8oOCvTacawJF7xdarJ3zOUA_V2TkEjbcZpVxjgPSUmhpbKRSFOaHdkcL_wKfMKt8CUgUVPFAtih_84uLLDhWYpGseRp6e14iH-dLa5nlZLWPnlV0w-VH35-Xev73LkcbSaydfRyWZQ5KZiGGlIEnA3dDVQ-qca6ztGRZRpYL3lR3NwFG2a4DkUVUxJSc077QUVx4f81Mv3BJCBepFDuJ8oLuOLshF0pJM_J8R3V9bn9Dq1OQaUM6cGNAQtRocOg5ebMDghAzXBSSHzWAFxewg-Xq9L_HFy8nF7baAi3hVeVqLXBQrVnZskiX18wEgJwBvbBFWiUpESR08jcssbV9ebV6Yp5WEOyUIQsFRF0In4dO0Y8zZzLyYN2eNn5HhJLtGY1OgqOk0hITz3WdE6CzrASdtyb1BsCI0Iu8HpTr8dLrxxEFhDmmKFN6eAHXqEadqDRUWw2sbDSiOLBWnU4iPuJlhhmoZWI_P3bY_HlIDozOSN_7hu9ac8vzpjPa_EtWP6K-5I58DgxlF-EUe0z-DslT_gJwDjbYjp3Hz14dvH37VbnrrVIZKCfzZ1eSZ4hE0moKATPaiFxeCK7lLYQf9NMvBS6w7oB5eOw-sBtAzsl4XrxhA3QhLaCesut4D6T_84cTflu98Wf-X_jPOmYsLuDpk4vfWOlUE-1P69poktSu9I4qnLry3Cwfs8-IHE2XqT3Ll4KaNh2js2XX9cbDR2etdIdBPN25U1txiZhxi3UT_1rvoxFoZg7RP3K7gHIzErEetj6uQ2F1vU3zasoetB_dUFkBx05ABRE.Yb6XntawePpprz6-RmSU0w; intercom-session-dgkjq2bp=NUMvVmZ5Y0pZc1ZNOGREa0g3NXRPRTFrNWZZTno4ZEdkUU5nemlsUXFEQ3ZMWXZyUWdHMHVUTzljVlhvUzJvby0taTFPYTh6dVNLSTRQVGFWbHVUVzhBdz09--c687bc31c7992f6240f09052cdafcecd009e1819; _uasid="Z0FBQUFBQmxhaGFsamRiWGpKaTFpeEdCVTBwUGpDYkMxNkZFY2xxUFhldF9Ba0o2WEtRRUh6N2dncTdJc2JHaU1aME1mVzk0UXl4YzdLS3cydFVjWF92b3hQekJvcmo3d2RGVWVuVUJRZ1JtMG1WaXNKZjZQT0hHdTZuaDB6STAxOTAzc1FiTTd4UnUyb2wyLWdrdzhHMGFwZHhSeDBVaXR1bVA0QWFDTWh6dHFDZlYwTDcwblRGWUY2anI4N2E3ZWRhek45eE9CQ1VBLXBnQW1na1BNVlROYmR1c1VUTV9IR0hFdWtyM1N4Rm9yOXZ3QXNnaUNLdUthOU4wRE9hbkFPWVUzMFd3U2YxT1N4QmVkM0RpZjdQcUFxczQxaWE4NnpWVjZTY3plc2JnaTk5ZklrSk0yYU9vS0I5VmE3SHA1ckpzN3hpdGhsb3BSUzRTX3JuREpOQTFmcl8xeldUUFpnPT0="; __cf_bm=sZv6L2xOAnAtQtjJb4imTJr.d0MYZ0.jLW_5S2E6JXk-1701451429-0-AXoEOULWXFtrCy03iiVbQPNglP0qQh6jDPA3YK+MW33Bm4tS7Fqjw2hrna/ezJl2Y8vW5QWSAXHI59Rp7+l3eMg=; __cflb=0H28vVfF4aAyg2hkHEuhVVUPGkAFmYvk6wuu5GU2dfj; _dd_s=rum=0&expire=1701452504590',
    'origin': 'https://chat.openai.com',
    'referer': 'https://chat.openai.com/c/4e2c0235-bd88-48d1-a667-bdd4931a7386',
    'sec-ch-ua': '"Opera";v="105", "Chromium";v="119", "Not?A_Brand";v="24"',
    'sec-ch-ua-mobile': '?0',
    'sec-ch-ua-platform': '"Linux"',
    'sec-fetch-dest': 'empty',
    'sec-fetch-mode': 'cors',
    'sec-fetch-site': 'same-origin',
    'user-agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/119.0.0.0 Safari/537.36 OPR/105.0.0.0'
};

const data = {
  action: 'next',
  messages: [
    {
      id: 'aaa272c6-d90b-4f51-90df-dd673308c003',
      author: {
        role: 'user',
      },
      content: {
        content_type: 'text',
        parts: ['hi'],
      },
      metadata: {},
    },
  ],
  conversation_id: '4e2c0235-bd88-48d1-a667-bdd4931a7386',
  parent_message_id: 'c02465d3-94ce-4a26-a97a-19dc79e489ea',
  model: 'text-davinci-002-render-sha',
  timezone_offset_min: -330,
  suggestions: [],
  history_and_training_disabled: false,
  arkose_token: null,
  conversation_mode: {
    kind: 'primary_assistant',
  },
  force_paragen: false,
  force_rate_limit: false,
};

fetch(url, {
  method: 'POST',
  headers: headers,
  body: JSON.stringify(data),
})
  .then(response => console.log(response))
