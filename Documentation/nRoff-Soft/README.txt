NroffEdit Readmefile

Version 2.08

By Stefan Santesson
3xA Security AB, Sweden


Installl Instructions:  Open the Zip file and:

For Mac:
   Drag the NroffEdit.app to you applications folder
   

For Windows:
   Move the NroffEdit folder in the zip file to any folder of your choice on
   your disk. Start application by double clicking the NroffEdit.jar file.

   Alternatively enter the following from command line:
      java -jar NroffEdit.jar 

   This application requires Java VM 1.6. It can be obtained from:
   (http://www.java.com/en/download/)



Changing the default nroff template:

For Mac:

   Edit the content of the empty.nroff file in the /Contents/Resources/Java
   folder in your NroffEdit Application.

   You can access these files by right-clicking the NroffEdit application
   and select "Show Package Contents"


For Windows:

   Edit the content of the empty.nroff file in your C:\NroffEdit folder.



This Nroff editor supports the following formatting commands

Directives:
          .in x       Set indent to x spaces from left column.
          .nf         Nofill. Subsequent output lines are neither filled nor adjusted.
                      Input text lines are copied directly to output lines without.
                      regard for the current line length.
          .fi         Fill subsequent lines until page width.
          .ce x       Center the next x lines.
          .ti x       Next line is temporary indent with x spaces, then
                      back to normal indent.
          .bp         Break page.
          .br         Break line.
          .sp [x]     Vertical space, x lines.
          .ne x       Keep next x lines on same page.
          .KS         Keep togeather start marker.
          .KE         Keep togeather on same page from .KS to here.
 
          .tl 'left'center'right'   Three part title, used to construct front page
                                    headers on Internet-drafts. The center text is usually
                                    omitted, specifying .tl 'left text''right text'
                                    The text components are placed at the start and end of
                                    the 72 character line.


Escape Sequence:
           \&         Non-printing character - can be use to express
                      information that otherwise would be treated as a
                      directive. E.g. "\&.ti 0", displays ".ti 0"
                      instead of using it as directive
           \%         Disable hyphenation for the following word. E.g \%Internet-Draft
                      will keep "Internet-Draft on the same line.
           \0         Space before number but keep on same line. E.g.
                      BCP\078 will be
                      displayed as BCP 78, but kept on the same line.
           \"         Subsequent text is treated as comment. Uses
                      leading dot for whole line comment

NroffEdit Specific
           .\" \# TOC Invokes a managed Table of Content for the
                      document. The managed Area will start from "TOC"
                      and end with the corresponding "ETC" command.
           .\" \# ETC Ends the managed Table of Content Area
           .\" \# TDn Sets the Table of Content depth. E.g. if TD4 are
                      set, the TOC will Include a title starting with
                      1.2.3.4, but not on that starts with 1.2.3.4.5
          .\" \# REF  Invokes a managed reference list for the document. The line
                      following the "TOC" directive specifies the references to be included
                      using the syntax: .\" \# [RFC]nnnn[;label], ... , [RFC]nnnn[;label]
          .\" \# ERF  Ends the managed reference list.


