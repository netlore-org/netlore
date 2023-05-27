/*
 * Copyright (c) 2023 Netlore Team
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * This code is part of Njord (HTML, CSS Parser) Component
 * of Netlore project that can be found at the github
 * repository at:
 *  - https://github.com/netlore-org/netlore
 */

#include <netlore/netlore.h>
#include <netlore/netlore_utils.h>

#include <netlore/bolly/njord/njord_css_properties.h>

css_properties_t
njord_parse_css_property(char* css_string_property)
{
    /* Change this string to lower characters */
    netlore_to_lower_string(css_string_property);

	if (strcmp(css_string_property, "-webkit-line-clamp"))
		return WebkitLineClamp;
	if (strcmp(css_string_property, "accent-color"))
		return AccentColor;
	if (strcmp(css_string_property, "align-content"))
		return AlignContent;
	if (strcmp(css_string_property, "align-items"))
		return AlignItems;
	if (strcmp(css_string_property, "align-self"))
		return AlignSelf;
	if (strcmp(css_string_property, "alignment-baseline"))
		return AlignmentBaseline;
	if (strcmp(css_string_property, "all"))
		return All;
	if (strcmp(css_string_property, "animation"))
		return Animation;
	if (strcmp(css_string_property, "animation-composition"))
		return AnimationComposition;
	if (strcmp(css_string_property, "animation-delay"))
		return AnimationDelay;
	if (strcmp(css_string_property, "animation-direction"))
		return AnimationDirection;
	if (strcmp(css_string_property, "animation-duration"))
		return AnimationDuration;
	if (strcmp(css_string_property, "animation-fill-mode"))
		return AnimationFillMode;
	if (strcmp(css_string_property, "animation-iteration-count"))
		return AnimationIterationCount;
	if (strcmp(css_string_property, "animation-name"))
		return AnimationName;
	if (strcmp(css_string_property, "animation-play-state"))
		return AnimationPlayState;
	if (strcmp(css_string_property, "animation-range"))
		return AnimationRange;
	if (strcmp(css_string_property, "animation-range-end"))
		return AnimationRangeEnd;
	if (strcmp(css_string_property, "animation-range-start"))
		return AnimationRangeStart;
	if (strcmp(css_string_property, "animation-timeline"))
		return AnimationTimeline;
	if (strcmp(css_string_property, "animation-timing-function"))
		return AnimationTimingFunction;
	if (strcmp(css_string_property, "appearance"))
		return Appearance;
	if (strcmp(css_string_property, "aspect-ratio"))
		return AspectRatio;
	if (strcmp(css_string_property, "azimuth"))
		return Azimuth;
	if (strcmp(css_string_property, "backface-visibility"))
		return BackfaceVisibility;
	if (strcmp(css_string_property, "background"))
		return Background;
	if (strcmp(css_string_property, "background-attachment"))
		return BackgroundAttachment;
	if (strcmp(css_string_property, "background-blend-mode"))
		return BackgroundBlendMode;
	if (strcmp(css_string_property, "background-clip"))
		return BackgroundClip;
	if (strcmp(css_string_property, "background-color"))
		return BackgroundColor;
	if (strcmp(css_string_property, "background-image"))
		return BackgroundImage;
	if (strcmp(css_string_property, "background-origin"))
		return BackgroundOrigin;
	if (strcmp(css_string_property, "background-position"))
		return BackgroundPosition;
	if (strcmp(css_string_property, "background-repeat"))
		return BackgroundRepeat;
	if (strcmp(css_string_property, "background-size"))
		return BackgroundSize;
	if (strcmp(css_string_property, "baseline-shift"))
		return BaselineShift;
	if (strcmp(css_string_property, "baseline-source"))
		return BaselineSource;
	if (strcmp(css_string_property, "block-ellipsis"))
		return BlockEllipsis;
	if (strcmp(css_string_property, "block-size"))
		return BlockSize;
	if (strcmp(css_string_property, "block-step"))
		return BlockStep;
	if (strcmp(css_string_property, "block-step-align"))
		return BlockStepAlign;
	if (strcmp(css_string_property, "block-step-insert"))
		return BlockStepInsert;
	if (strcmp(css_string_property, "block-step-round"))
		return BlockStepRound;
	if (strcmp(css_string_property, "block-step-size"))
		return BlockStepSize;
	if (strcmp(css_string_property, "bookmark-label"))
		return BookmarkLabel;
	if (strcmp(css_string_property, "bookmark-level"))
		return BookmarkLevel;
	if (strcmp(css_string_property, "bookmark-state"))
		return BookmarkState;
	if (strcmp(css_string_property, "border"))
		return Border;
	if (strcmp(css_string_property, "border-block"))
		return BorderBlock;
	if (strcmp(css_string_property, "border-block-color"))
		return BorderBlockColor;
	if (strcmp(css_string_property, "border-block-end"))
		return BorderBlockEnd;
	if (strcmp(css_string_property, "border-block-end-color"))
		return BorderBlockEndColor;
	if (strcmp(css_string_property, "border-block-end-style"))
		return BorderBlockEndStyle;
	if (strcmp(css_string_property, "border-block-end-width"))
		return BorderBlockEndWidth;
	if (strcmp(css_string_property, "border-block-start"))
		return BorderBlockStart;
	if (strcmp(css_string_property, "border-block-start-color"))
		return BorderBlockStartColor;
	if (strcmp(css_string_property, "border-block-start-style"))
		return BorderBlockStartStyle;
	if (strcmp(css_string_property, "border-block-start-width"))
		return BorderBlockStartWidth;
	if (strcmp(css_string_property, "border-block-style"))
		return BorderBlockStyle;
	if (strcmp(css_string_property, "border-block-width"))
		return BorderBlockWidth;
	if (strcmp(css_string_property, "border-bottom"))
		return BorderBottom;
	if (strcmp(css_string_property, "border-bottom-color"))
		return BorderBottomColor;
	if (strcmp(css_string_property, "border-bottom-left-radius"))
		return BorderBottomLeftRadius;
	if (strcmp(css_string_property, "border-bottom-right-radius"))
		return BorderBottomRightRadius;
	if (strcmp(css_string_property, "border-bottom-style"))
		return BorderBottomStyle;
	if (strcmp(css_string_property, "border-bottom-width"))
		return BorderBottomWidth;
	if (strcmp(css_string_property, "border-boundary"))
		return BorderBoundary;
	if (strcmp(css_string_property, "border-collapse"))
		return BorderCollapse;
	if (strcmp(css_string_property, "border-color"))
		return BorderColor;
	if (strcmp(css_string_property, "border-end-end-radius"))
		return BorderEndEndRadius;
	if (strcmp(css_string_property, "border-end-start-radius"))
		return BorderEndStartRadius;
	if (strcmp(css_string_property, "border-image"))
		return BorderImage;
	if (strcmp(css_string_property, "border-image-outset"))
		return BorderImageOutset;
	if (strcmp(css_string_property, "border-image-repeat"))
		return BorderImageRepeat;
	if (strcmp(css_string_property, "border-image-slice"))
		return BorderImageSlice;
	if (strcmp(css_string_property, "border-image-source"))
		return BorderImageSource;
	if (strcmp(css_string_property, "border-image-width"))
		return BorderImageWidth;
	if (strcmp(css_string_property, "border-inline"))
		return BorderInline;
	if (strcmp(css_string_property, "border-inline-color"))
		return BorderInlineColor;
	if (strcmp(css_string_property, "border-inline-end"))
		return BorderInlineEnd;
	if (strcmp(css_string_property, "border-inline-end-color"))
		return BorderInlineEndColor;
	if (strcmp(css_string_property, "border-inline-end-style"))
		return BorderInlineEndStyle;
	if (strcmp(css_string_property, "border-inline-end-width"))
		return BorderInlineEndWidth;
	if (strcmp(css_string_property, "border-inline-start"))
		return BorderInlineStart;
	if (strcmp(css_string_property, "border-inline-start-color"))
		return BorderInlineStartColor;
	if (strcmp(css_string_property, "border-inline-start-style"))
		return BorderInlineStartStyle;
	if (strcmp(css_string_property, "border-inline-start-width"))
		return BorderInlineStartWidth;
	if (strcmp(css_string_property, "border-inline-style"))
		return BorderInlineStyle;
	if (strcmp(css_string_property, "border-inline-width"))
		return BorderInlineWidth;
	if (strcmp(css_string_property, "border-left"))
		return BorderLeft;
	if (strcmp(css_string_property, "border-left-color"))
		return BorderLeftColor;
	if (strcmp(css_string_property, "border-left-style"))
		return BorderLeftStyle;
	if (strcmp(css_string_property, "border-left-width"))
		return BorderLeftWidth;
	if (strcmp(css_string_property, "border-radius"))
		return BorderRadius;
	if (strcmp(css_string_property, "border-right"))
		return BorderRight;
	if (strcmp(css_string_property, "border-right-color"))
		return BorderRightColor;
	if (strcmp(css_string_property, "border-right-style"))
		return BorderRightStyle;
	if (strcmp(css_string_property, "border-right-width"))
		return BorderRightWidth;
	if (strcmp(css_string_property, "border-spacing"))
		return BorderSpacing;
	if (strcmp(css_string_property, "border-start-end-radius"))
		return BorderStartEndRadius;
	if (strcmp(css_string_property, "border-start-start-radius"))
		return BorderStartStartRadius;
	if (strcmp(css_string_property, "border-style"))
		return BorderStyle;
	if (strcmp(css_string_property, "border-top"))
		return BorderTop;
	if (strcmp(css_string_property, "border-top-color"))
		return BorderTopColor;
	if (strcmp(css_string_property, "border-top-left-radius"))
		return BorderTopLeftRadius;
	if (strcmp(css_string_property, "border-top-right-radius"))
		return BorderTopRightRadius;
	if (strcmp(css_string_property, "border-top-style"))
		return BorderTopStyle;
	if (strcmp(css_string_property, "border-top-width"))
		return BorderTopWidth;
	if (strcmp(css_string_property, "border-width"))
		return BorderWidth;
	if (strcmp(css_string_property, "bottom"))
		return Bottom;
	if (strcmp(css_string_property, "box-decoration-break"))
		return BoxDecorationBreak;
	if (strcmp(css_string_property, "box-shadow"))
		return BoxShadow;
	if (strcmp(css_string_property, "box-sizing"))
		return BoxSizing;
	if (strcmp(css_string_property, "box-snap"))
		return BoxSnap;
	if (strcmp(css_string_property, "break-after"))
		return BreakAfter;
	if (strcmp(css_string_property, "break-before"))
		return BreakBefore;
	if (strcmp(css_string_property, "break-inside"))
		return BreakInside;
	if (strcmp(css_string_property, "caption-side"))
		return CaptionSide;
	if (strcmp(css_string_property, "caret"))
		return Caret;
	if (strcmp(css_string_property, "caret-color"))
		return CaretColor;
	if (strcmp(css_string_property, "caret-shape"))
		return CaretShape;
	if (strcmp(css_string_property, "chains"))
		return Chains;
	if (strcmp(css_string_property, "clear"))
		return Clear;
	if (strcmp(css_string_property, "clip"))
		return Clip;
	if (strcmp(css_string_property, "clip-path"))
		return ClipPath;
	if (strcmp(css_string_property, "clip-rule"))
		return ClipRule;
	if (strcmp(css_string_property, "color"))
		return Color;
	if (strcmp(css_string_property, "color-adjust"))
		return ColorAdjust;
	if (strcmp(css_string_property, "color-interpolation-filters"))
		return ColorInterpolationFilters;
	if (strcmp(css_string_property, "color-scheme"))
		return ColorScheme;
	if (strcmp(css_string_property, "column-count"))
		return ColumnCount;
	if (strcmp(css_string_property, "column-fill"))
		return ColumnFill;
	if (strcmp(css_string_property, "column-gap"))
		return ColumnGap;
	if (strcmp(css_string_property, "column-rule"))
		return ColumnRule;
	if (strcmp(css_string_property, "column-rule-color"))
		return ColumnRuleColor;
	if (strcmp(css_string_property, "column-rule-style"))
		return ColumnRuleStyle;
	if (strcmp(css_string_property, "column-rule-width"))
		return ColumnRuleWidth;
	if (strcmp(css_string_property, "column-span"))
		return ColumnSpan;
	if (strcmp(css_string_property, "column-width"))
		return ColumnWidth;
	if (strcmp(css_string_property, "columns"))
		return Columns;
	if (strcmp(css_string_property, "contain"))
		return Contain;
	if (strcmp(css_string_property, "contain-intrinsic-block-size"))
		return ContainIntrinsicBlockSize;
	if (strcmp(css_string_property, "contain-intrinsic-height"))
		return ContainIntrinsicHeight;
	if (strcmp(css_string_property, "contain-intrinsic-inline-size"))
		return ContainIntrinsicInlineSize;
	if (strcmp(css_string_property, "contain-intrinsic-size"))
		return ContainIntrinsicSize;
	if (strcmp(css_string_property, "contain-intrinsic-width"))
		return ContainIntrinsicWidth;
	if (strcmp(css_string_property, "container"))
		return Container;
	if (strcmp(css_string_property, "container-name"))
		return ContainerName;
	if (strcmp(css_string_property, "container-type"))
		return ContainerType;
	if (strcmp(css_string_property, "content"))
		return Content;
	if (strcmp(css_string_property, "content-visibility"))
		return ContentVisibility;
	if (strcmp(css_string_property, "continue"))
		return Continue;
	if (strcmp(css_string_property, "counter-increment"))
		return CounterIncrement;
	if (strcmp(css_string_property, "counter-reset"))
		return CounterReset;
	if (strcmp(css_string_property, "counter-set"))
		return CounterSet;
	if (strcmp(css_string_property, "cue"))
		return Cue;
	if (strcmp(css_string_property, "cue-after"))
		return CueAfter;
	if (strcmp(css_string_property, "cue-before"))
		return CueBefore;
	if (strcmp(css_string_property, "cursor"))
		return Cursor;
	if (strcmp(css_string_property, "direction"))
		return Direction;
	if (strcmp(css_string_property, "display"))
		return Display;
	if (strcmp(css_string_property, "dominant-baseline"))
		return DominantBaseline;
	if (strcmp(css_string_property, "elevation"))
		return Elevation;
	if (strcmp(css_string_property, "empty-cells"))
		return EmptyCells;
	if (strcmp(css_string_property, "fill"))
		return Fill;
	if (strcmp(css_string_property, "fill-break"))
		return FillBreak;
	if (strcmp(css_string_property, "fill-color"))
		return FillColor;
	if (strcmp(css_string_property, "fill-image"))
		return FillImage;
	if (strcmp(css_string_property, "fill-opacity"))
		return FillOpacity;
	if (strcmp(css_string_property, "fill-origin"))
		return FillOrigin;
	if (strcmp(css_string_property, "fill-position"))
		return FillPosition;
	if (strcmp(css_string_property, "fill-repeat"))
		return FillRepeat;
	if (strcmp(css_string_property, "fill-rule"))
		return FillRule;
	if (strcmp(css_string_property, "fill-size"))
		return FillSize;
	if (strcmp(css_string_property, "filter"))
		return Filter;
	if (strcmp(css_string_property, "flex"))
		return Flex;
	if (strcmp(css_string_property, "flex-basis"))
		return FlexBasis;
	if (strcmp(css_string_property, "flex-direction"))
		return FlexDirection;
	if (strcmp(css_string_property, "flex-flow"))
		return FlexFlow;
	if (strcmp(css_string_property, "flex-grow"))
		return FlexGrow;
	if (strcmp(css_string_property, "flex-shrink"))
		return FlexShrink;
	if (strcmp(css_string_property, "flex-wrap"))
		return FlexWrap;
	if (strcmp(css_string_property, "float"))
		return Float;
	if (strcmp(css_string_property, "float-defer"))
		return FloatDefer;
	if (strcmp(css_string_property, "float-offset"))
		return FloatOffset;
	if (strcmp(css_string_property, "float-reference"))
		return FloatReference;
	if (strcmp(css_string_property, "flood-color"))
		return FloodColor;
	if (strcmp(css_string_property, "flood-opacity"))
		return FloodOpacity;
	if (strcmp(css_string_property, "flow"))
		return Flow;
	if (strcmp(css_string_property, "flow-from"))
		return FlowFrom;
	if (strcmp(css_string_property, "flow-into"))
		return FlowInto;
	if (strcmp(css_string_property, "font"))
		return Font;
	if (strcmp(css_string_property, "font-family"))
		return FontFamily;
	if (strcmp(css_string_property, "font-feature-settings"))
		return FontFeatureSettings;
	if (strcmp(css_string_property, "font-kerning"))
		return FontKerning;
	if (strcmp(css_string_property, "font-language-override"))
		return FontLanguageOverride;
	if (strcmp(css_string_property, "font-optical-sizing"))
		return FontOpticalSizing;
	if (strcmp(css_string_property, "font-palette"))
		return FontPalette;
	if (strcmp(css_string_property, "font-size"))
		return FontSize;
	if (strcmp(css_string_property, "font-size-adjust"))
		return FontSizeAdjust;
	if (strcmp(css_string_property, "font-stretch"))
		return FontStretch;
	if (strcmp(css_string_property, "font-style"))
		return FontStyle;
	if (strcmp(css_string_property, "font-synthesis"))
		return FontSynthesis;
	if (strcmp(css_string_property, "font-synthesis-small-caps"))
		return FontSynthesisSmallCaps;
	if (strcmp(css_string_property, "font-synthesis-style"))
		return FontSynthesisStyle;
	if (strcmp(css_string_property, "font-synthesis-weight"))
		return FontSynthesisWeight;
	if (strcmp(css_string_property, "font-variant"))
		return FontVariant;
	if (strcmp(css_string_property, "font-variant-alternates"))
		return FontVariantAlternates;
	if (strcmp(css_string_property, "font-variant-caps"))
		return FontVariantCaps;
	if (strcmp(css_string_property, "font-variant-east-asian"))
		return FontVariantEastAsian;
	if (strcmp(css_string_property, "font-variant-emoji"))
		return FontVariantEmoji;
	if (strcmp(css_string_property, "font-variant-ligatures"))
		return FontVariantLigatures;
	if (strcmp(css_string_property, "font-variant-numeric"))
		return FontVariantNumeric;
	if (strcmp(css_string_property, "font-variant-position"))
		return FontVariantPosition;
	if (strcmp(css_string_property, "font-variation-settings"))
		return FontVariationSettings;
	if (strcmp(css_string_property, "font-weight"))
		return FontWeight;
	if (strcmp(css_string_property, "footnote-display"))
		return FootnoteDisplay;
	if (strcmp(css_string_property, "footnote-policy"))
		return FootnotePolicy;
	if (strcmp(css_string_property, "forced-color-adjust"))
		return ForcedColorAdjust;
	if (strcmp(css_string_property, "gap"))
		return Gap;
	if (strcmp(css_string_property, "glyph-orientation-vertical"))
		return GlyphOrientationVertical;
	if (strcmp(css_string_property, "grid"))
		return Grid;
	if (strcmp(css_string_property, "grid-area"))
		return GridArea;
	if (strcmp(css_string_property, "grid-auto-columns"))
		return GridAutoColumns;
	if (strcmp(css_string_property, "grid-auto-flow"))
		return GridAutoFlow;
	if (strcmp(css_string_property, "grid-auto-rows"))
		return GridAutoRows;
	if (strcmp(css_string_property, "grid-column"))
		return GridColumn;
	if (strcmp(css_string_property, "grid-column-end"))
		return GridColumnEnd;
	if (strcmp(css_string_property, "grid-column-start"))
		return GridColumnStart;
	if (strcmp(css_string_property, "grid-row"))
		return GridRow;
	if (strcmp(css_string_property, "grid-row-end"))
		return GridRowEnd;
	if (strcmp(css_string_property, "grid-row-start"))
		return GridRowStart;
	if (strcmp(css_string_property, "grid-template"))
		return GridTemplate;
	if (strcmp(css_string_property, "grid-template-areas"))
		return GridTemplateAreas;
	if (strcmp(css_string_property, "grid-template-columns"))
		return GridTemplateColumns;
	if (strcmp(css_string_property, "grid-template-rows"))
		return GridTemplateRows;
	if (strcmp(css_string_property, "hanging-punctuation"))
		return HangingPunctuation;
	if (strcmp(css_string_property, "height"))
		return Height;
	if (strcmp(css_string_property, "hyphenate-character"))
		return HyphenateCharacter;
	if (strcmp(css_string_property, "hyphenate-limit-chars"))
		return HyphenateLimitChars;
	if (strcmp(css_string_property, "hyphenate-limit-last"))
		return HyphenateLimitLast;
	if (strcmp(css_string_property, "hyphenate-limit-lines"))
		return HyphenateLimitLines;
	if (strcmp(css_string_property, "hyphenate-limit-zone"))
		return HyphenateLimitZone;
	if (strcmp(css_string_property, "hyphens"))
		return Hyphens;
	if (strcmp(css_string_property, "image-orientation"))
		return ImageOrientation;
	if (strcmp(css_string_property, "image-rendering"))
		return ImageRendering;
	if (strcmp(css_string_property, "image-resolution"))
		return ImageResolution;
	if (strcmp(css_string_property, "initial-letter"))
		return InitialLetter;
	if (strcmp(css_string_property, "initial-letter-align"))
		return InitialLetterAlign;
	if (strcmp(css_string_property, "initial-letter-wrap"))
		return InitialLetterWrap;
	if (strcmp(css_string_property, "inline-size"))
		return InlineSize;
	if (strcmp(css_string_property, "inline-sizing"))
		return InlineSizing;
	if (strcmp(css_string_property, "input-security"))
		return InputSecurity;
	if (strcmp(css_string_property, "inset"))
		return Inset;
	if (strcmp(css_string_property, "inset-block"))
		return InsetBlock;
	if (strcmp(css_string_property, "inset-block-end"))
		return InsetBlockEnd;
	if (strcmp(css_string_property, "inset-block-start"))
		return InsetBlockStart;
	if (strcmp(css_string_property, "inset-inline"))
		return InsetInline;
	if (strcmp(css_string_property, "inset-inline-end"))
		return InsetInlineEnd;
	if (strcmp(css_string_property, "inset-inline-start"))
		return InsetInlineStart;
	if (strcmp(css_string_property, "isolation"))
		return Isolation;
	if (strcmp(css_string_property, "justify-content"))
		return JustifyContent;
	if (strcmp(css_string_property, "justify-items"))
		return JustifyItems;
	if (strcmp(css_string_property, "justify-self"))
		return JustifySelf;
	if (strcmp(css_string_property, "left"))
		return Left;
	if (strcmp(css_string_property, "letter-spacing"))
		return LetterSpacing;
	if (strcmp(css_string_property, "lighting-color"))
		return LightingColor;
	if (strcmp(css_string_property, "line-break"))
		return LineBreak;
	if (strcmp(css_string_property, "line-clamp"))
		return LineClamp;
	if (strcmp(css_string_property, "line-grid"))
		return LineGrid;
	if (strcmp(css_string_property, "line-height"))
		return LineHeight;
	if (strcmp(css_string_property, "line-height-step"))
		return LineHeightStep;
	if (strcmp(css_string_property, "line-padding"))
		return LinePadding;
	if (strcmp(css_string_property, "line-snap"))
		return LineSnap;
	if (strcmp(css_string_property, "list-style"))
		return ListStyle;
	if (strcmp(css_string_property, "list-style-image"))
		return ListStyleImage;
	if (strcmp(css_string_property, "list-style-position"))
		return ListStylePosition;
	if (strcmp(css_string_property, "list-style-type"))
		return ListStyleType;
	if (strcmp(css_string_property, "margin"))
		return Margin;
	if (strcmp(css_string_property, "margin-block"))
		return MarginBlock;
	if (strcmp(css_string_property, "margin-block-end"))
		return MarginBlockEnd;
	if (strcmp(css_string_property, "margin-block-start"))
		return MarginBlockStart;
	if (strcmp(css_string_property, "margin-bottom"))
		return MarginBottom;
	if (strcmp(css_string_property, "margin-break"))
		return MarginBreak;
	if (strcmp(css_string_property, "margin-inline"))
		return MarginInline;
	if (strcmp(css_string_property, "margin-inline-end"))
		return MarginInlineEnd;
	if (strcmp(css_string_property, "margin-inline-start"))
		return MarginInlineStart;
	if (strcmp(css_string_property, "margin-left"))
		return MarginLeft;
	if (strcmp(css_string_property, "margin-right"))
		return MarginRight;
	if (strcmp(css_string_property, "margin-top"))
		return MarginTop;
	if (strcmp(css_string_property, "margin-trim"))
		return MarginTrim;
	if (strcmp(css_string_property, "marker"))
		return Marker;
	if (strcmp(css_string_property, "marker-end"))
		return MarkerEnd;
	if (strcmp(css_string_property, "marker-knockout-left"))
		return MarkerKnockoutLeft;
	if (strcmp(css_string_property, "marker-knockout-right"))
		return MarkerKnockoutRight;
	if (strcmp(css_string_property, "marker-mid"))
		return MarkerMid;
	if (strcmp(css_string_property, "marker-pattern"))
		return MarkerPattern;
	if (strcmp(css_string_property, "marker-segment"))
		return MarkerSegment;
	if (strcmp(css_string_property, "marker-side"))
		return MarkerSide;
	if (strcmp(css_string_property, "marker-start"))
		return MarkerStart;
	if (strcmp(css_string_property, "mask"))
		return Mask;
	if (strcmp(css_string_property, "mask-border"))
		return MaskBorder;
	if (strcmp(css_string_property, "mask-border-mode"))
		return MaskBorderMode;
	if (strcmp(css_string_property, "mask-border-outset"))
		return MaskBorderOutset;
	if (strcmp(css_string_property, "mask-border-repeat"))
		return MaskBorderRepeat;
	if (strcmp(css_string_property, "mask-border-slice"))
		return MaskBorderSlice;
	if (strcmp(css_string_property, "mask-border-source"))
		return MaskBorderSource;
	if (strcmp(css_string_property, "mask-border-width"))
		return MaskBorderWidth;
	if (strcmp(css_string_property, "mask-clip"))
		return MaskClip;
	if (strcmp(css_string_property, "mask-composite"))
		return MaskComposite;
	if (strcmp(css_string_property, "mask-image"))
		return MaskImage;
	if (strcmp(css_string_property, "mask-mode"))
		return MaskMode;
	if (strcmp(css_string_property, "mask-origin"))
		return MaskOrigin;
	if (strcmp(css_string_property, "mask-position"))
		return MaskPosition;
	if (strcmp(css_string_property, "mask-repeat"))
		return MaskRepeat;
	if (strcmp(css_string_property, "mask-size"))
		return MaskSize;
	if (strcmp(css_string_property, "mask-type"))
		return MaskType;
	if (strcmp(css_string_property, "max-block-size"))
		return MaxBlockSize;
	if (strcmp(css_string_property, "max-height"))
		return MaxHeight;
	if (strcmp(css_string_property, "max-inline-size"))
		return MaxInlineSize;
	if (strcmp(css_string_property, "max-lines"))
		return MaxLines;
	if (strcmp(css_string_property, "max-width"))
		return MaxWidth;
	if (strcmp(css_string_property, "min-block-size"))
		return MinBlockSize;
	if (strcmp(css_string_property, "min-height"))
		return MinHeight;
	if (strcmp(css_string_property, "min-inline-size"))
		return MinInlineSize;
	if (strcmp(css_string_property, "min-intrinsic-sizing"))
		return MinIntrinsicSizing;
	if (strcmp(css_string_property, "min-width"))
		return MinWidth;
	if (strcmp(css_string_property, "mix-blend-mode"))
		return MixBlendMode;
	if (strcmp(css_string_property, "nav-down"))
		return NavDown;
	if (strcmp(css_string_property, "nav-left"))
		return NavLeft;
	if (strcmp(css_string_property, "nav-right"))
		return NavRight;
	if (strcmp(css_string_property, "nav-up"))
		return NavUp;
	if (strcmp(css_string_property, "object-fit"))
		return ObjectFit;
	if (strcmp(css_string_property, "object-position"))
		return ObjectPosition;
	if (strcmp(css_string_property, "offset"))
		return Offset;
	if (strcmp(css_string_property, "offset-anchor"))
		return OffsetAnchor;
	if (strcmp(css_string_property, "offset-distance"))
		return OffsetDistance;
	if (strcmp(css_string_property, "offset-path"))
		return OffsetPath;
	if (strcmp(css_string_property, "offset-position"))
		return OffsetPosition;
	if (strcmp(css_string_property, "offset-rotate"))
		return OffsetRotate;
	if (strcmp(css_string_property, "opacity"))
		return Opacity;
	if (strcmp(css_string_property, "order"))
		return Order;
	if (strcmp(css_string_property, "orphans"))
		return Orphans;
	if (strcmp(css_string_property, "outline"))
		return Outline;
	if (strcmp(css_string_property, "outline-color"))
		return OutlineColor;
	if (strcmp(css_string_property, "outline-offset"))
		return OutlineOffset;
	if (strcmp(css_string_property, "outline-style"))
		return OutlineStyle;
	if (strcmp(css_string_property, "outline-width"))
		return OutlineWidth;
	if (strcmp(css_string_property, "overflow"))
		return Overflow;
	if (strcmp(css_string_property, "overflow-anchor"))
		return OverflowAnchor;
	if (strcmp(css_string_property, "overflow-block"))
		return OverflowBlock;
	if (strcmp(css_string_property, "overflow-clip-margin"))
		return OverflowClipMargin;
	if (strcmp(css_string_property, "overflow-clip-margin-block"))
		return OverflowClipMarginBlock;
	if (strcmp(css_string_property, "overflow-clip-margin-block-end"))
		return OverflowClipMarginBlockEnd;
	if (strcmp(css_string_property, "overflow-clip-margin-block-start"))
		return OverflowClipMarginBlockStart;
	if (strcmp(css_string_property, "overflow-clip-margin-bottom"))
		return OverflowClipMarginBottom;
	if (strcmp(css_string_property, "overflow-clip-margin-inline"))
		return OverflowClipMarginInline;
	if (strcmp(css_string_property, "overflow-clip-margin-inline-end"))
		return OverflowClipMarginInlineEnd;
	if (strcmp(css_string_property, "overflow-clip-margin-inline-start"))
		return OverflowClipMarginInlineStart;
	if (strcmp(css_string_property, "overflow-clip-margin-left"))
		return OverflowClipMarginLeft;
	if (strcmp(css_string_property, "overflow-clip-margin-right"))
		return OverflowClipMarginRight;
	if (strcmp(css_string_property, "overflow-clip-margin-top"))
		return OverflowClipMarginTop;
	if (strcmp(css_string_property, "overflow-inline"))
		return OverflowInline;
	if (strcmp(css_string_property, "overflow-wrap"))
		return OverflowWrap;
	if (strcmp(css_string_property, "overflow-x"))
		return OverflowX;
	if (strcmp(css_string_property, "overflow-y"))
		return OverflowY;
	if (strcmp(css_string_property, "overscroll-behavior"))
		return OverscrollBehavior;
	if (strcmp(css_string_property, "overscroll-behavior-block"))
		return OverscrollBehaviorBlock;
	if (strcmp(css_string_property, "overscroll-behavior-inline"))
		return OverscrollBehaviorInline;
	if (strcmp(css_string_property, "overscroll-behavior-x"))
		return OverscrollBehaviorX;
	if (strcmp(css_string_property, "overscroll-behavior-y"))
		return OverscrollBehaviorY;
	if (strcmp(css_string_property, "padding"))
		return Padding;
	if (strcmp(css_string_property, "padding-block"))
		return PaddingBlock;
	if (strcmp(css_string_property, "padding-block-end"))
		return PaddingBlockEnd;
	if (strcmp(css_string_property, "padding-block-start"))
		return PaddingBlockStart;
	if (strcmp(css_string_property, "padding-bottom"))
		return PaddingBottom;
	if (strcmp(css_string_property, "padding-inline"))
		return PaddingInline;
	if (strcmp(css_string_property, "padding-inline-end"))
		return PaddingInlineEnd;
	if (strcmp(css_string_property, "padding-inline-start"))
		return PaddingInlineStart;
	if (strcmp(css_string_property, "padding-left"))
		return PaddingLeft;
	if (strcmp(css_string_property, "padding-right"))
		return PaddingRight;
	if (strcmp(css_string_property, "padding-top"))
		return PaddingTop;
	if (strcmp(css_string_property, "page"))
		return Page;
	if (strcmp(css_string_property, "page-break-after"))
		return PageBreakAfter;
	if (strcmp(css_string_property, "page-break-before"))
		return PageBreakBefore;
	if (strcmp(css_string_property, "page-break-inside"))
		return PageBreakInside;
	if (strcmp(css_string_property, "pause"))
		return Pause;
	if (strcmp(css_string_property, "pause-after"))
		return PauseAfter;
	if (strcmp(css_string_property, "pause-before"))
		return PauseBefore;
	if (strcmp(css_string_property, "perspective"))
		return Perspective;
	if (strcmp(css_string_property, "perspective-origin"))
		return PerspectiveOrigin;
	if (strcmp(css_string_property, "pitch"))
		return Pitch;
	if (strcmp(css_string_property, "pitch-range"))
		return PitchRange;
	if (strcmp(css_string_property, "place-content"))
		return PlaceContent;
	if (strcmp(css_string_property, "place-items"))
		return PlaceItems;
	if (strcmp(css_string_property, "place-self"))
		return PlaceSelf;
	if (strcmp(css_string_property, "play-during"))
		return PlayDuring;
	if (strcmp(css_string_property, "pointer-events"))
		return PointerEvents;
	if (strcmp(css_string_property, "position"))
		return Position;
	if (strcmp(css_string_property, "print-color-adjust"))
		return PrintColorAdjust;
	if (strcmp(css_string_property, "property-name"))
		return PropertyName;
	if (strcmp(css_string_property, "quotes"))
		return Quotes;
	if (strcmp(css_string_property, "region-fragment"))
		return RegionFragment;
	if (strcmp(css_string_property, "resize"))
		return Resize;
	if (strcmp(css_string_property, "rest"))
		return Rest;
	if (strcmp(css_string_property, "rest-after"))
		return RestAfter;
	if (strcmp(css_string_property, "rest-before"))
		return RestBefore;
	if (strcmp(css_string_property, "richness"))
		return Richness;
	if (strcmp(css_string_property, "right"))
		return Right;
	if (strcmp(css_string_property, "rotate"))
		return Rotate;
	if (strcmp(css_string_property, "row-gap"))
		return RowGap;
	if (strcmp(css_string_property, "ruby-align"))
		return RubyAlign;
	if (strcmp(css_string_property, "ruby-merge"))
		return RubyMerge;
	if (strcmp(css_string_property, "ruby-overhang"))
		return RubyOverhang;
	if (strcmp(css_string_property, "ruby-position"))
		return RubyPosition;
	if (strcmp(css_string_property, "running"))
		return Running;
	if (strcmp(css_string_property, "scale"))
		return Scale;
	if (strcmp(css_string_property, "scroll-behavior"))
		return ScrollBehavior;
	if (strcmp(css_string_property, "scroll-margin"))
		return ScrollMargin;
	if (strcmp(css_string_property, "scroll-margin-block"))
		return ScrollMarginBlock;
	if (strcmp(css_string_property, "scroll-margin-block-end"))
		return ScrollMarginBlockEnd;
	if (strcmp(css_string_property, "scroll-margin-block-start"))
		return ScrollMarginBlockStart;
	if (strcmp(css_string_property, "scroll-margin-bottom"))
		return ScrollMarginBottom;
	if (strcmp(css_string_property, "scroll-margin-inline"))
		return ScrollMarginInline;
	if (strcmp(css_string_property, "scroll-margin-inline-end"))
		return ScrollMarginInlineEnd;
	if (strcmp(css_string_property, "scroll-margin-inline-start"))
		return ScrollMarginInlineStart;
	if (strcmp(css_string_property, "scroll-margin-left"))
		return ScrollMarginLeft;
	if (strcmp(css_string_property, "scroll-margin-right"))
		return ScrollMarginRight;
	if (strcmp(css_string_property, "scroll-margin-top"))
		return ScrollMarginTop;
	if (strcmp(css_string_property, "scroll-padding"))
		return ScrollPadding;
	if (strcmp(css_string_property, "scroll-padding-block"))
		return ScrollPaddingBlock;
	if (strcmp(css_string_property, "scroll-padding-block-end"))
		return ScrollPaddingBlockEnd;
	if (strcmp(css_string_property, "scroll-padding-block-start"))
		return ScrollPaddingBlockStart;
	if (strcmp(css_string_property, "scroll-padding-bottom"))
		return ScrollPaddingBottom;
	if (strcmp(css_string_property, "scroll-padding-inline"))
		return ScrollPaddingInline;
	if (strcmp(css_string_property, "scroll-padding-inline-end"))
		return ScrollPaddingInlineEnd;
	if (strcmp(css_string_property, "scroll-padding-inline-start"))
		return ScrollPaddingInlineStart;
	if (strcmp(css_string_property, "scroll-padding-left"))
		return ScrollPaddingLeft;
	if (strcmp(css_string_property, "scroll-padding-right"))
		return ScrollPaddingRight;
	if (strcmp(css_string_property, "scroll-padding-top"))
		return ScrollPaddingTop;
	if (strcmp(css_string_property, "scroll-snap-align"))
		return ScrollSnapAlign;
	if (strcmp(css_string_property, "scroll-snap-stop"))
		return ScrollSnapStop;
	if (strcmp(css_string_property, "scroll-snap-type"))
		return ScrollSnapType;
	if (strcmp(css_string_property, "scroll-timeline"))
		return ScrollTimeline;
	if (strcmp(css_string_property, "scroll-timeline-attachment"))
		return ScrollTimelineAttachment;
	if (strcmp(css_string_property, "scroll-timeline-axis"))
		return ScrollTimelineAxis;
	if (strcmp(css_string_property, "scroll-timeline-name"))
		return ScrollTimelineName;
	if (strcmp(css_string_property, "scrollbar-color"))
		return ScrollbarColor;
	if (strcmp(css_string_property, "scrollbar-gutter"))
		return ScrollbarGutter;
	if (strcmp(css_string_property, "scrollbar-width"))
		return ScrollbarWidth;
	if (strcmp(css_string_property, "shape-image-threshold"))
		return ShapeImageThreshold;
	if (strcmp(css_string_property, "shape-inside"))
		return ShapeInside;
	if (strcmp(css_string_property, "shape-margin"))
		return ShapeMargin;
	if (strcmp(css_string_property, "shape-outside"))
		return ShapeOutside;
	if (strcmp(css_string_property, "spatial-navigation-action"))
		return SpatialNavigationAction;
	if (strcmp(css_string_property, "spatial-navigation-contain"))
		return SpatialNavigationContain;
	if (strcmp(css_string_property, "spatial-navigation-function"))
		return SpatialNavigationFunction;
	if (strcmp(css_string_property, "speak"))
		return Speak;
	if (strcmp(css_string_property, "speak-as"))
		return SpeakAs;
	if (strcmp(css_string_property, "speak-header"))
		return SpeakHeader;
	if (strcmp(css_string_property, "speak-numeral"))
		return SpeakNumeral;
	if (strcmp(css_string_property, "speak-punctuation"))
		return SpeakPunctuation;
	if (strcmp(css_string_property, "speech-rate"))
		return SpeechRate;
	if (strcmp(css_string_property, "stress"))
		return Stress;
	if (strcmp(css_string_property, "string-set"))
		return StringSet;
	if (strcmp(css_string_property, "stroke"))
		return Stroke;
	if (strcmp(css_string_property, "stroke-align"))
		return StrokeAlign;
	if (strcmp(css_string_property, "stroke-alignment"))
		return StrokeAlignment;
	if (strcmp(css_string_property, "stroke-break"))
		return StrokeBreak;
	if (strcmp(css_string_property, "stroke-color"))
		return StrokeColor;
	if (strcmp(css_string_property, "stroke-dash-corner"))
		return StrokeDashCorner;
	if (strcmp(css_string_property, "stroke-dash-justify"))
		return StrokeDashJustify;
	if (strcmp(css_string_property, "stroke-dashadjust"))
		return StrokeDashadjust;
	if (strcmp(css_string_property, "stroke-dasharray"))
		return StrokeDasharray;
	if (strcmp(css_string_property, "stroke-dashcorner"))
		return StrokeDashcorner;
	if (strcmp(css_string_property, "stroke-dashoffset"))
		return StrokeDashoffset;
	if (strcmp(css_string_property, "stroke-image"))
		return StrokeImage;
	if (strcmp(css_string_property, "stroke-linecap"))
		return StrokeLinecap;
	if (strcmp(css_string_property, "stroke-linejoin"))
		return StrokeLinejoin;
	if (strcmp(css_string_property, "stroke-miterlimit"))
		return StrokeMiterlimit;
	if (strcmp(css_string_property, "stroke-opacity"))
		return StrokeOpacity;
	if (strcmp(css_string_property, "stroke-origin"))
		return StrokeOrigin;
	if (strcmp(css_string_property, "stroke-position"))
		return StrokePosition;
	if (strcmp(css_string_property, "stroke-repeat"))
		return StrokeRepeat;
	if (strcmp(css_string_property, "stroke-size"))
		return StrokeSize;
	if (strcmp(css_string_property, "stroke-width"))
		return StrokeWidth;
	if (strcmp(css_string_property, "tab-size"))
		return TabSize;
	if (strcmp(css_string_property, "table-layout"))
		return TableLayout;
	if (strcmp(css_string_property, "text-align"))
		return TextAlign;
	if (strcmp(css_string_property, "text-align-all"))
		return TextAlignAll;
	if (strcmp(css_string_property, "text-align-last"))
		return TextAlignLast;
	if (strcmp(css_string_property, "text-autospace"))
		return TextAutospace;
	if (strcmp(css_string_property, "text-box-edge"))
		return TextBoxEdge;
	if (strcmp(css_string_property, "text-box-trim"))
		return TextBoxTrim;
	if (strcmp(css_string_property, "text-combine-upright"))
		return TextCombineUpright;
	if (strcmp(css_string_property, "text-decoration"))
		return TextDecoration;
	if (strcmp(css_string_property, "text-decoration-color"))
		return TextDecorationColor;
	if (strcmp(css_string_property, "text-decoration-line"))
		return TextDecorationLine;
	if (strcmp(css_string_property, "text-decoration-skip"))
		return TextDecorationSkip;
	if (strcmp(css_string_property, "text-decoration-skip-box"))
		return TextDecorationSkipBox;
	if (strcmp(css_string_property, "text-decoration-skip-ink"))
		return TextDecorationSkipInk;
	if (strcmp(css_string_property, "text-decoration-skip-inset"))
		return TextDecorationSkipInset;
	if (strcmp(css_string_property, "text-decoration-skip-self"))
		return TextDecorationSkipSelf;
	if (strcmp(css_string_property, "text-decoration-skip-spaces"))
		return TextDecorationSkipSpaces;
	if (strcmp(css_string_property, "text-decoration-style"))
		return TextDecorationStyle;
	if (strcmp(css_string_property, "text-decoration-thickness"))
		return TextDecorationThickness;
	if (strcmp(css_string_property, "text-decoration-trim"))
		return TextDecorationTrim;
	if (strcmp(css_string_property, "text-emphasis"))
		return TextEmphasis;
	if (strcmp(css_string_property, "text-emphasis-color"))
		return TextEmphasisColor;
	if (strcmp(css_string_property, "text-emphasis-position"))
		return TextEmphasisPosition;
	if (strcmp(css_string_property, "text-emphasis-skip"))
		return TextEmphasisSkip;
	if (strcmp(css_string_property, "text-emphasis-style"))
		return TextEmphasisStyle;
	if (strcmp(css_string_property, "text-group-align"))
		return TextGroupAlign;
	if (strcmp(css_string_property, "text-indent"))
		return TextIndent;
	if (strcmp(css_string_property, "text-justify"))
		return TextJustify;
	if (strcmp(css_string_property, "text-orientation"))
		return TextOrientation;
	if (strcmp(css_string_property, "text-overflow"))
		return TextOverflow;
	if (strcmp(css_string_property, "text-shadow"))
		return TextShadow;
	if (strcmp(css_string_property, "text-spacing"))
		return TextSpacing;
	if (strcmp(css_string_property, "text-spacing-trim"))
		return TextSpacingTrim;
	if (strcmp(css_string_property, "text-transform"))
		return TextTransform;
	if (strcmp(css_string_property, "text-underline-offset"))
		return TextUnderlineOffset;
	if (strcmp(css_string_property, "text-underline-position"))
		return TextUnderlinePosition;
	if (strcmp(css_string_property, "text-wrap"))
		return TextWrap;
	if (strcmp(css_string_property, "top"))
		return Top;
	if (strcmp(css_string_property, "transform"))
		return Transform;
	if (strcmp(css_string_property, "transform-box"))
		return TransformBox;
	if (strcmp(css_string_property, "transform-origin"))
		return TransformOrigin;
	if (strcmp(css_string_property, "transform-style"))
		return TransformStyle;
	if (strcmp(css_string_property, "transition"))
		return Transition;
	if (strcmp(css_string_property, "transition-delay"))
		return TransitionDelay;
	if (strcmp(css_string_property, "transition-duration"))
		return TransitionDuration;
	if (strcmp(css_string_property, "transition-property"))
		return TransitionProperty;
	if (strcmp(css_string_property, "transition-timing-function"))
		return TransitionTimingFunction;
	if (strcmp(css_string_property, "translate"))
		return Translate;
	if (strcmp(css_string_property, "unicode-bidi"))
		return UnicodeBidi;
	if (strcmp(css_string_property, "user-select"))
		return UserSelect;
	if (strcmp(css_string_property, "vertical-align"))
		return VerticalAlign;
	if (strcmp(css_string_property, "view-timeline"))
		return ViewTimeline;
	if (strcmp(css_string_property, "view-timeline-attachment"))
		return ViewTimelineAttachment;
	if (strcmp(css_string_property, "view-timeline-axis"))
		return ViewTimelineAxis;
	if (strcmp(css_string_property, "view-timeline-inset"))
		return ViewTimelineInset;
	if (strcmp(css_string_property, "view-timeline-name"))
		return ViewTimelineName;
	if (strcmp(css_string_property, "view-transition-name"))
		return ViewTransitionName;
	if (strcmp(css_string_property, "visibility"))
		return Visibility;
	if (strcmp(css_string_property, "voice-balance"))
		return VoiceBalance;
	if (strcmp(css_string_property, "voice-duration"))
		return VoiceDuration;
	if (strcmp(css_string_property, "voice-family"))
		return VoiceFamily;
	if (strcmp(css_string_property, "voice-pitch"))
		return VoicePitch;
	if (strcmp(css_string_property, "voice-range"))
		return VoiceRange;
	if (strcmp(css_string_property, "voice-rate"))
		return VoiceRate;
	if (strcmp(css_string_property, "voice-stress"))
		return VoiceStress;
	if (strcmp(css_string_property, "voice-volume"))
		return VoiceVolume;
	if (strcmp(css_string_property, "volume"))
		return Volume;
	if (strcmp(css_string_property, "white-space"))
		return WhiteSpace;
	if (strcmp(css_string_property, "white-space-collapse"))
		return WhiteSpaceCollapse;
	if (strcmp(css_string_property, "white-space-trim"))
		return WhiteSpaceTrim;
	if (strcmp(css_string_property, "widows"))
		return Widows;
	if (strcmp(css_string_property, "width"))
		return Width;
	if (strcmp(css_string_property, "will-change"))
		return WillChange;
	if (strcmp(css_string_property, "word-boundary-detection"))
		return WordBoundaryDetection;
	if (strcmp(css_string_property, "word-boundary-expansion"))
		return WordBoundaryExpansion;
	if (strcmp(css_string_property, "word-break"))
		return WordBreak;
	if (strcmp(css_string_property, "word-spacing"))
		return WordSpacing;
	if (strcmp(css_string_property, "word-wrap"))
		return WordWrap;
	if (strcmp(css_string_property, "wrap-after"))
		return WrapAfter;
	if (strcmp(css_string_property, "wrap-before"))
		return WrapBefore;
	if (strcmp(css_string_property, "wrap-flow"))
		return WrapFlow;
	if (strcmp(css_string_property, "wrap-inside"))
		return WrapInside;
	if (strcmp(css_string_property, "wrap-through"))
		return WrapThrough;
	if (strcmp(css_string_property, "writing-mode"))
		return WritingMode;
	if (strcmp(css_string_property, "z-index"))
		return ZIndex;

    /* If our string isn't any of these we return
     * -1 as information that it's invalid style
     * rule name */
    return -1;
}