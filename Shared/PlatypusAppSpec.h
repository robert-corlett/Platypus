/*
Copyright (c) 2003-2015, Sveinbjorn Thordarson <sveinbjornt@gmail.com
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the FreeBSD Project.
 */

// PlatypusAppSpec is a wrapper class around an NSDictionary containing
// all the information / specifications for creating a Platypus application.

#import <Cocoa/Cocoa.h>
#import "Common.h"
#import "ScriptAnalyser.h"
#import "PlatypusUtility.h"

#define MAX_APPSPEC_PROPERTIES    255 // whatever...

@interface PlatypusAppSpec : NSObject
{
    NSMutableDictionary *properties;
    NSString *error;
}
- (PlatypusAppSpec *)initWithDefaults;
- (PlatypusAppSpec *)initWithDefaultsFromScript:(NSString *)scriptPath;
- (PlatypusAppSpec *)initWithDictionary:(NSDictionary *)dict;
- (PlatypusAppSpec *)initWithProfile:(NSString *)filePath;
+ (PlatypusAppSpec *)specWithDefaults;
+ (PlatypusAppSpec *)specWithDictionary:(NSDictionary *)dict;
+ (PlatypusAppSpec *)specFromProfile:(NSString *)filePath;
+ (PlatypusAppSpec *)specWithDefaultsFromScript:(NSString *)scriptPath;
- (void)setDefaults;
- (void)setDefaultsForScript:(NSString *)scriptPath;
- (BOOL)create;
- (NSDictionary *)infoPlist;
- (BOOL)verify;
- (void)report:(NSString *)str;
- (void)dumpToFile:(NSString *)filePath;
- (void)dump;
- (NSString *)commandString;
- (void)setProperty:(id)property forKey:(NSString *)theKey;
- (id)propertyForKey:(NSString *)theKey;
- (NSDictionary *)properties;
- (void)addProperties:(NSDictionary *)dict;
- (NSString *)error;
+ (NSString *)standardBundleIdForAppName:(NSString *)name usingDefaults:(BOOL)def;
@end
