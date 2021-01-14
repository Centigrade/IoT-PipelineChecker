// WiFi access data
//const char *ssid = "Centigrade-Legacy";
const char *ssid = "Teutonet";

// Gitlab Server
//const char* host = "gitlab.intranet.centigrade.de";
const char* host = "gitlab.centigrade.de";

//Centigrade´s gitlab webpage certificate
const char* CENTIGRADE_GITLAB_CERTIFICATE = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIG7zCCBdegAwIBAgIRAPQs3jIPnU5f8IQuthyQno4wDQYJKoZIhvcNAQELBQAw\n" \
"gY8xCzAJBgNVBAYTAkdCMRswGQYDVQQIExJHcmVhdGVyIE1hbmNoZXN0ZXIxEDAO\n" \
"BgNVBAcTB1NhbGZvcmQxGDAWBgNVBAoTD1NlY3RpZ28gTGltaXRlZDE3MDUGA1UE\n" \
"AxMuU2VjdGlnbyBSU0EgRG9tYWluIFZhbGlkYXRpb24gU2VjdXJlIFNlcnZlciBD\n" \
"QTAeFw0xOTEwMjkwMDAwMDBaFw0yMjAxMzAwMDAwMDBaMFsxITAfBgNVBAsTGERv\n" \
"bWFpbiBDb250cm9sIFZhbGlkYXRlZDEcMBoGA1UECxMTQ09NT0RPIFNTTCBXaWxk\n" \
"Y2FyZDEYMBYGA1UEAwwPKi5jZW50aWdyYWRlLmRlMIIBIjANBgkqhkiG9w0BAQEF\n" \
"AAOCAQ8AMIIBCgKCAQEAyc97Xx4aTv/le+KhYYXIe7Fc7hFzrTjn/D24uT+VkEDB\n" \
"tki+GiunfnI5uB2hNZNdLahU5OifKxs43qz2RO/68WIG+fbCMgljHQ+bmZ+RKwth\n" \
"CfHbOAznSkJNguFaeUiUe/qeC+xi511tb0i6pFpZX1BXmWnSs0k8dyJx9Uno8kSz\n" \
"VVIlXoHOTc7XJ2/EUBbRf47T0hEB8ua34BPP7UaWuolt+ZYcnCYNjRqoRhtR6fZp\n" \
"8C/+fnySpa/bI0YX6Q+AM2yCjgw7De34Qg+m7kvP07hfg+rNZ/Lkp2sizltVmMeG\n" \
"zhedcnxxdwBjoKDiG//nAtTd3yOIwldsB5ipdIbOTwIDAQABo4IDdzCCA3MwHwYD\n" \
"VR0jBBgwFoAUjYxexFStiuF36Zv5mwXhuAGNYeEwHQYDVR0OBBYEFJF/HsUGOHe0\n" \
"PTLBd/GVyX4YeceaMA4GA1UdDwEB/wQEAwIFoDAMBgNVHRMBAf8EAjAAMB0GA1Ud\n" \
"JQQWMBQGCCsGAQUFBwMBBggrBgEFBQcDAjBJBgNVHSAEQjBAMDQGCysGAQQBsjEB\n" \
"AgIHMCUwIwYIKwYBBQUHAgEWF2h0dHBzOi8vc2VjdGlnby5jb20vQ1BTMAgGBmeB\n" \
"DAECATCBhAYIKwYBBQUHAQEEeDB2ME8GCCsGAQUFBzAChkNodHRwOi8vY3J0LnNl\n" \
"Y3RpZ28uY29tL1NlY3RpZ29SU0FEb21haW5WYWxpZGF0aW9uU2VjdXJlU2VydmVy\n" \
"Q0EuY3J0MCMGCCsGAQUFBzABhhdodHRwOi8vb2NzcC5zZWN0aWdvLmNvbTApBgNV\n" \
"HREEIjAggg8qLmNlbnRpZ3JhZGUuZGWCDWNlbnRpZ3JhZGUuZGUwggH1BgorBgEE\n" \
"AdZ5AgQCBIIB5QSCAeEB3wB2AEalVet1+pEgMLWiiWn0830RLEF0vv1JuIWr8vxw\n" \
"/m1HAAABbhgpywEAAAQDAEcwRQIgejksnCslcOzUVhudvPGQ3B7MPGCpry1DwNgL\n" \
"u/bbcjsCIQD614LuG13C6CxGzjhRC0tp+YuUaIndDRUtrBuJ7WxdyAB2AFWB1MIW\n" \
"kDYBSuoLm1c8U/DA5Dh4cCUIFy+jqh0HE9MMAAABbhgpy2kAAAQDAEcwRQIgNiVX\n" \
"6a8zT049laI8rRONe0AKsgn/r5/y3Kh6Bjoe3BUCIQDpnl5fw+QrQlHI/M5Og2eN\n" \
"IfR8uUyxcPLFreq/bAbGugB2ACJFRQdZVSRWlj+hL/H3bYbgIyZjrcBLf13Gg1xu\n" \
"4g8CAAABbhgpzAQAAAQDAEcwRQIhAItxCzAI8xYLLIPhzPCb0SVKRiNfUQA7SiBp\n" \
"8E98G2BqAiBu0kX4C9dcQ2ZGZTYsFB4MsoqVpND0dP25f2rZ4GLw7wB1AG9Tdqwx\n" \
"8DEZ2JkApFEV/3cVHBHZAsEAKQaNsgiaN9kTAAABbhgpy+kAAAQDAEYwRAIgSol/\n" \
"NGM8sZXsry1U+Z/K77ENPFN7pOA0ubPXDb4WSewCIBvXwtphi4FI3XHEriroNu92\n" \
"cRKj/LHEP9q+TUlBPKhdMA0GCSqGSIb3DQEBCwUAA4IBAQAnhuCLT6OqwsZZLS3L\n" \
"tJnOAphTQnpVBbZ16zCnAKObgHL8M/X8TVgwhCUd1ai+pq/hISsGqrShoLkYOODU\n" \
"u8bvbjp4K5kIAemljkmZYJVKKZijUyRVUITgdS7Wa9QhIZBdaHxTt0MNA7Np8SFg\n" \
"KoLEMWdzy5YGHG3ncOVZP15uD5UyVI4Q19FUI3OBpdIO6cYHeR0C/QmL0g5scMp1\n" \
"svaFe8uw/WDBtzML+CHHp4YQt0i1WD3Nu9ud1bTFlWFbwyeOxSE8OYrXEeDCGcLe\n" \
"tACNIZ/EUwXa9STxnu4pe4nNRro3PF+XnF//UWjJPLJlqAFQG6/iKCbi3cS4RIeL\n" \
"mrZE\n" \
"-----END CERTIFICATE-----\n";


// LED output mapping
const int greenLEDPin = 19;    
const int blueLEDPin  = 16; 
const int redLEDPin   = 15; 

// How often to poll for updates
const int updateDelayMillis = 5000;
long lastUpdateMillis = 0;

String result;

//Here i list up the different state i will be working with using the fonction ENUMERATE
enum PipelineState{
  PASSED, 
  RUNNING,
  UNKNOWN, 
  FAILED 
};

PipelineState pState = UNKNOWN;
