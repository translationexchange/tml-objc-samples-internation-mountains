/*
 *  Copyright (c) 2015 Translation Exchange, Inc. All rights reserved.
 *
 *  _______                  _       _   _             ______          _
 * |__   __|                | |     | | (_)           |  ____|        | |
 *    | |_ __ __ _ _ __  ___| | __ _| |_ _  ___  _ __ | |__  __  _____| |__   __ _ _ __   __ _  ___
 *    | | '__/ _` | '_ \/ __| |/ _` | __| |/ _ \| '_ \|  __| \ \/ / __| '_ \ / _` | '_ \ / _` |/ _ \
 *    | | | | (_| | | | \__ \ | (_| | |_| | (_) | | | | |____ >  < (__| | | | (_| | | | | (_| |  __/
 *    |_|_|  \__,_|_| |_|___/_|\__,_|\__|_|\___/|_| |_|______/_/\_\___|_| |_|\__,_|_| |_|\__, |\___|
 *                                                                                        __/ |
 *                                                                                       |___/
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */

#import <Foundation/Foundation.h>
#import "TmlLanguageContext.h"
#import "TmlBase.h"

@interface TmlLanguageContextRule : TmlBase

// Holds reference to the language context it belongs to
@property(nonatomic, weak) TmlLanguageContext *languageContext;

// Unique key of the context within the language
@property(nonatomic, strong) NSString *keyword;

// Description of the rule
@property(nonatomic, strong) NSString *description;

// Examples of the rule application
@property(nonatomic, strong) NSString *examples;

// Conditions in symbolic notation
@property(nonatomic, strong) NSString *conditions;

// Optimized conditions parsed into an array
@property(nonatomic, strong) NSArray *compiledConditions;

// Default rule key
+ (BOOL) isFallback: (NSString *) keyword;

// Returns @YES or @NO if the rule is a default fallback rule, like "other"
- (BOOL) isFallback;

// Compiled conditions expression
- (NSArray *) conditionsExpression;

// Always returns @YES or @NO for the result of the rule evaluation
- (NSNumber *) evaluate: (NSDictionary *) vars;

@end
