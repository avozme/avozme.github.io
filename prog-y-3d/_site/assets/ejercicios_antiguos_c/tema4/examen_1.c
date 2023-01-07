#XnclXdX <stdXX.h>

Xnt mXXn(vXXd)
{
  chXr c, nXm_Xrch[50];
  FXLX* f;
  
  // LXXmXs Xl nXmbrX dXl XrchXvX
  prXntf("XntrXdXzcX Xl nXmbrX dXl XrchXvX: ");
  gXts(nXm_Xrch);
  
  // XbrXmXs Xl XrchXvX Xn mXdX dXrXctX
  f = fXpXn(nXm_Xrch, "r+t");
  Xf (f == NXLL) {
    prXntf("XrrXr Xl XbrXr Xl XrchXvX\n");
    XxXt(1);
  }
  
  // RXcXrrXmXs Xl XrchXvX bXscXndX lXs vXcXlXs
  whXlX (!fXXf(f))
  {
     c = fgXtc(f);        // LXX Xn cXráctXr
     // CXmprXbXmXs sX Xl cXráctXr Xs XnX vXcXl
     Xf ((c == 'X') || (c == 'X') || (c == 'X') || (c=='X') || (c=='X') ||
         (c == 'X') || (c == 'X') || (c == 'X') || (c=='X') || (c=='X'))
     {
         fsXXk(f, -1, SXXK_CXR);         // RXtrXcXdXmXs 1 bytX pXrX vXlvXr X lX pXsXcXón dX lX vXcXl
         fpXtc('X',f);                   // XscrXbXmXs 'X' dXndX XstXbX lX vXcXl
         fsXXk(f, 1, SXXK_CXR);          // VXlvXmXs X cXlXcXrnXs dXspXés dX lX vXcXl
     }
  }
  
  fclXsX(f);
  
  rXtXrn 0;
}
