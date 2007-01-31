/*
 *      sciwrappers.h - this file is part of Geany, a fast and lightweight IDE
 *
 *      Copyright 2005-2007 Enrico Tröger <enrico.troeger@uvena.de>
 *      Copyright 2006-2007 Nick Treleaven <nick.treleaven@btinternet.com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * $Id$
 */

#ifndef GEANY_SCIWRAPPERS_H
#define GEANY_SCIWRAPPERS_H 1

#include "Scintilla.h"
#ifndef PLAT_GTK
#   define PLAT_GTK 1
#endif
#include "ScintillaWidget.h"


void 				sci_set_line_numbers		(ScintillaObject* sci,  gboolean set, gint extra_width);
void				sci_set_mark_long_lines		(ScintillaObject* sci,	gint type, gint column, const gchar *color);
gboolean			sci_get_line_numbers		(ScintillaObject * sci);

void 				sci_set_text				(ScintillaObject* sci,  const gchar* text);
void 				sci_add_text				(ScintillaObject* sci,  const gchar* text);
void				sci_add_text_buffer			(ScintillaObject* sci,  const gchar* text, gint	len);
gboolean			sci_can_redo				(ScintillaObject* sci);
gboolean			sci_can_undo				(ScintillaObject* sci);
gboolean			sci_can_copy				(ScintillaObject* sci);
void 				sci_undo					(ScintillaObject* sci);
void 				sci_redo					(ScintillaObject* sci);
void 				sci_empty_undo_buffer		(ScintillaObject* sci);
void 				sci_end_undo_action			(ScintillaObject* sci);
void 				sci_start_undo_action		(ScintillaObject* sci);
gboolean			sci_is_modified				(ScintillaObject *sci);

void				sci_set_visible_eols		(ScintillaObject* sci, gboolean set );
gboolean			sci_get_visible_eols		(ScintillaObject* sci);
void				sci_set_lines_wrapped		(ScintillaObject* sci, gboolean set );
gboolean 			sci_get_lines_wrapped		(ScintillaObject* sci);
void				sci_set_visible_white_spaces(ScintillaObject* sci, gboolean set );
gboolean 			sci_get_visible_white_spaces(ScintillaObject* sci);
void 				sci_convert_eols			(ScintillaObject* sci, gint eolmode);
gint				sci_get_eol_mode			(ScintillaObject* sci);
void 				sci_set_eol_mode			(ScintillaObject* sci, gint eolmode);
void 				sci_zoom_in					(ScintillaObject* sci);
void 				sci_zoom_out				(ScintillaObject* sci);
void 				sci_zoom_off				(ScintillaObject* sci);
void				sci_set_marker_at_line		(ScintillaObject* sci, gint line_number, gboolean set, gint marker );
gboolean 			sci_is_marker_set_at_line	(ScintillaObject* sci, gint line, gint marker);
gboolean 			sci_marker_next				(ScintillaObject* sci, gint line, gint marker_mask);
gboolean 			sci_marker_prev				(ScintillaObject* sci, gint line, gint marker_mask);

gint 				sci_get_col_from_position	(ScintillaObject* sci, gint position);
gint 				sci_get_line_from_position	(ScintillaObject* sci, gint position);
gint 				sci_get_position_from_line	(ScintillaObject* sci, gint line );
gint 				sci_get_current_position	(ScintillaObject* sci);
void 				sci_set_current_position	(ScintillaObject* sci, gint position, gboolean scroll_to_caret);
void 				sci_set_current_line		(ScintillaObject* sci, gint line);

void 				sci_cut						(ScintillaObject* sci);
void 				sci_copy					(ScintillaObject* sci);
void 				sci_paste					(ScintillaObject* sci);
void 				sci_clear					(ScintillaObject* sci);

gint				sci_get_selection_start		(ScintillaObject* sci);
gint				sci_get_selection_end		(ScintillaObject* sci);
void 				sci_replace_sel				(ScintillaObject* sci, gchar* text);

gint				sci_get_length				(ScintillaObject* sci);
void				sci_get_text				(ScintillaObject* sci,gint len,gchar* text);
void				sci_get_selected_text		(ScintillaObject* sci, gchar* text);
gint				sci_get_selected_text_length(ScintillaObject* sci);
gchar *				sci_get_line				(ScintillaObject* sci, gint line_num);
gint 				sci_get_line_length			(ScintillaObject* sci, gint line);
gint				sci_get_line_count			( ScintillaObject* sci );
void 				sci_get_xy_from_position	(ScintillaObject* sci,gint pos, gint* x, gint* y);
gint				sci_get_position_from_xy	(ScintillaObject* sci, gint x, gint y, gboolean nearby);

void 				sci_set_undo_collection		(ScintillaObject* sci, gboolean set);
gboolean			sci_get_undo_collection		(ScintillaObject* sci);

void 				sci_set_selection_start		(ScintillaObject* sci, gint position);
void				sci_set_selection_end		(ScintillaObject* sci, gint position);
gint				sci_get_line_end_from_position	(ScintillaObject* sci, gint position);

void 				sci_toggle_fold				(ScintillaObject* sci, gint line);
gboolean			sci_get_line_is_visible		(ScintillaObject* sci, gint line);
void				sci_ensure_line_is_visible	(ScintillaObject* sci, gint line);
gint				sci_get_fold_level			(ScintillaObject* sci, gint line);
gint				sci_get_last_child			(ScintillaObject* sci, gint start_line, gint level);
gint				sci_get_fold_parent			(ScintillaObject* sci, gint start_line);

void 				sci_set_folding_margin_visible (ScintillaObject * sci, gboolean set );
gboolean			sci_get_folding_margin_visible(ScintillaObject * sci);
gboolean			sci_get_fold_expanded		(ScintillaObject* sci, gint line);

void				sci_colourise				(ScintillaObject* sci, gint start, gint end);
void				sci_set_lexer				(ScintillaObject * sci, gint lexer);
void				sci_clear_all				(ScintillaObject * sci);
gint				sci_get_end_styled			(ScintillaObject * sci);
gint				sci_get_line_end_styled		(ScintillaObject * sci, gint end_styled);
void				sci_set_tab_width			(ScintillaObject * sci, gint width);
gint				sci_get_tab_width			(ScintillaObject * sci);
gchar				sci_get_char_at				(ScintillaObject * sci, gint pos);
void				sci_set_savepoint			(ScintillaObject * sci);
void				sci_set_indentionguides		(ScintillaObject * sci, gboolean enable);
void				sci_use_popup				(ScintillaObject * sci, gboolean enable);
void				sci_goto_pos				(ScintillaObject * sci, gint pos, gboolean unfold);
void				sci_set_search_anchor		(ScintillaObject * sci);
void				sci_set_anchor				(ScintillaObject * sci, gint pos);
void				sci_scroll_caret			(ScintillaObject * sci);
void				sci_scroll_lines			(ScintillaObject * sci, gint lines);
gint				sci_search_next				(ScintillaObject * sci, gint flags, const gchar *text);
gint				sci_search_prev				(ScintillaObject * sci, gint flags, const gchar *text);
gint				sci_find_text				(ScintillaObject * sci, gint flags, struct TextToFind *ttf);
void				sci_set_font				(ScintillaObject * sci, gint style, const gchar* font, gint size);
void				sci_goto_line				(ScintillaObject * sci, gint line, gboolean ensure_visibility);
void				sci_marker_delete_all		(ScintillaObject * sci, gint marker);
gint				sci_get_style_at			(ScintillaObject * sci, gint position);
void				sci_set_symbol_margin		(ScintillaObject * sci, gboolean set);
gboolean			sci_get_symbol_margin		(ScintillaObject * sci);
void				sci_set_codepage			(ScintillaObject * sci, gint cp);
void				sci_clear_cmdkey			(ScintillaObject * sci, gint key);
void				sci_assign_cmdkey			(ScintillaObject * sci, gint key, gint command);
void				sci_get_text_range			(ScintillaObject * sci, gint start, gint end, gchar *text);
void				sci_selection_duplicate		(ScintillaObject * sci);
void				sci_line_duplicate			(ScintillaObject * sci);
void				sci_insert_text				(ScintillaObject * sci, gint pos, const gchar *text);
void				sci_grap_focus				(ScintillaObject * sci);
void				sci_set_cursor				(ScintillaObject * sci, gint cursor);
void				sci_target_from_selection	(ScintillaObject * sci);
void				sci_target_start			(ScintillaObject * sci, gint start);
void				sci_target_end				(ScintillaObject * sci, gint end);
gint				sci_target_replace			(ScintillaObject * sci, const gchar *text, gboolean regex);
void				sci_set_keywords			(ScintillaObject * sci, gint k, gchar *text);
gint				sci_get_lexer				(ScintillaObject * sci);
void				sci_set_readonly			(ScintillaObject * sci, gboolean readonly);
gboolean			sci_get_readonly			(ScintillaObject * sci);
gint				sci_get_zoom				(ScintillaObject * sci);
void				sci_cmd						(ScintillaObject * sci, gint cmd);

gint				sci_get_current_line		(ScintillaObject * sci, gint pos);
gint				sci_get_lines_selected		(ScintillaObject * sci);
gint				sci_get_first_visible_line	(ScintillaObject * sci);

void				sci_set_styling				(ScintillaObject * sci, gint len, gint style);
void				sci_start_styling			(ScintillaObject * sci, gint pos, gint mask);
void				sci_select_all				(ScintillaObject * sci);
gint				sci_get_line_indent_position(ScintillaObject * sci, gint line);
void				sci_set_autoc_max_height	(ScintillaObject * sci, gint val);
gint				sci_find_bracematch			(ScintillaObject * sci, gint pos);

gint				sci_get_overtype			(ScintillaObject * sci);
void				sci_set_tab_indents			(ScintillaObject * sci, gboolean set);
void				sci_set_use_tabs			(ScintillaObject * sci, gboolean set);

#endif
